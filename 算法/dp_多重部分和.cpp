#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

//有n种不同大小的数字ai，每种各mi个，判断是否可以从这些数字中选出若干使它们的和恰好为K。
//可以转化成恰好装满的多重背包问题，重量为a[i]，价值也为a[i]，看最大价值是不是K
const int MAXN = 105;
//const int MAXM = 100000;
const int INF = 1 << 30;
int d[MAXN];

int main() {
	int n, k;
	int m[] = { 0,3,2,2 };
	n = 3; k = 17;
	int a[] = { 0,3,3,3,5,5,18,18 };
	int total = 7;

	fill(d, d + 1 + k, -INF);
	d[0] = 0;
	for (int i = 1; i <= 7; i++) {
		for (int j = k; j >=a[i]; j--) {
			d[j] = max(d[j], d[j - a[i]] + a[i]);
		}
	}
	if (d[k] == k) cout << "YES";
	else cout << "FALSE";

	return 0;
}