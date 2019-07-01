#include <iostream>

using namespace std;

int main() {
	int n, m;
	int num[105];
	while (scanf("%d %d", &n, &m) != EOF) {
		if (n == 0 && m == 0) break;
		bool flag = false;
		for (int i = 0; i < n; i++)
			cin >> num[i];
		for (int i = 0; i < n; i++) {
			if (!flag && m < num[0]) {
				cout << m << " ";
				cout << num[0] << " ";
				flag = true;
				continue;
			}
			if (flag || num[i] < m) {
				cout << num[i];
			}
			else {
				cout << m << " ";
				cout << num[i];
				flag = true;
			}
			if (i != n-1)
				cout << " ";
			else {
				if (!flag)
					cout <<" "<< m << endl;
				else
					cout << endl;
			}
		}
	}
	return 0;
}
