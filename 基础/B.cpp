#include <iostream>

using namespace std;

int main() {

	double ans = 0;
	int n, m;
	int arr[100];
	int sumarr[100];

	arr[0] = 2;
	sumarr[0] = 2;
	for (int i = 1; i < 100; i++) {
		arr[i] = (i + 1) * 2;
		sumarr[i] = sumarr[i - 1] + arr[i];
	}


	while (cin >> n >> m) {
		ans = sumarr[m-1] / m;
		cout << ans;

		for (int i = m; i < n - n % m; i += m) {
			cout << " ";
			ans = (sumarr[i+m-1] - sumarr[i - 1]) / m;
			cout << ans;
		}

		if (n%m) {
			cout << " ";
			ans = (sumarr[n-1] - sumarr[n - n % m-1]) / (n%m);
			cout << ans;
		}
		cout << endl;
	}


	return 0;
}