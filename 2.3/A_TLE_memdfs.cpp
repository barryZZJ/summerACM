//TLE
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
//倒着看当前列的最大值等于上一列

const int MAXN = 355;
int d[MAXN][MAXN];
int mp[MAXN][MAXN];
int ans = 0;

int dfs(int i,int j) {
	if (i == 1 && j == 1) return d[1][1];
	if (d[i][j]) return d[i][j];
	
	if (j > 1 && j < i) {
		int tmp = max(dfs(i - 1, j - 1), dfs(i - 1, j));
		return d[i][j] = tmp + mp[i][j];
	}
	else if (j == 1) return d[i][j] = dfs(i-1,1) + mp[i][j];
	else if (j == i) return d[i][j] = dfs(i-1,i-1) + mp[i][j];

}

int main() {
	int n;
	cin >> n;
	int tmp;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++) {
			cin >> mp[i][j];
		}
	}

	d[1][1] = mp[1][1];
	for (int i = 1;i <= n;i++) {
		if (dfs(n, i) > ans) ans = d[n][i];
	}
	cout << ans;

	return 0;
}