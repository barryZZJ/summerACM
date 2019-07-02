#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int dosum(int *sums, const int len) {
	int s[10];
	for (int i = 0;i < len;i++) {
		s[i] = sums[i];
	}

	for (int i = len - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++)
			s[j] += s[j + 1];
	}
	return s[0];
}

int main() {
	int nums[10];
	for (int i = 0;i < 10;i++) {
		nums[i] = i + 1;
	}
	int n, m;
	cin >> n >> m;
	do {
		if (dosum(nums, n) == m) break;
	} while (next_permutation(nums, nums + n));

	for (int i = 0;i < n;i++) {
		printf("%d ", nums[i]);
	}

	return 0;
}
