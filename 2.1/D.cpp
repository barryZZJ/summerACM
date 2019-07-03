
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

int nums[20];
int getInt(char(&s)[20]) {
	istringstream is(s);
	int i = 0;
	while (is >> nums[i]) {
		//cout << nums[i] << endl;
		i++;
	}
	return i;
}

int n = 0;

int main() {
	int T;
	cin >> T;
	getchar();
	while (T--) {

		int ans = 99999999;
		char tmp[20];
		cin.getline(tmp, 20);
		n = getInt(tmp);
		if (n == 1) {
			cout << nums[0] << endl;
			continue;
		}
		if (n == 2) {
			cout << abs(nums[1] - nums[0]) << endl;
			continue;
		}
		int cut;
		int sum1, sum2;
		cut = n / 2;

		do {
			sum1 = 0; sum2 = 0;
			if (nums[0] == 0 || nums[cut] == 0) continue;

			for (int a = 0; a < cut; a++)
				sum1 = sum1 * 10 + nums[a];

			for (int b = cut; b < n; b++)
				sum2 = sum2 * 10 + nums[b];

			ans = min(ans, abs(sum2 - sum1));



		} while (next_permutation(nums, nums + n));

		cout << ans << endl;

	}
	return 0;
}