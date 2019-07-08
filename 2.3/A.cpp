#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
//该行每个元素+=他左右儿子里大的那个，一直回溯到第一行，树根就是结果。

const int MAXN = 355;
//int d[MAXN][MAXN];
int mp[MAXN][MAXN];
//int ans = 0;

int main() {
	int n;
	cin >> n;
	//int tmp;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++) {
			cin >> mp[i][j];
		}
	}

	for (int i = n-1;i >= 1;i--) {
		for (int j = 1;j <= i;j++) {
			mp[i][j] += max(mp[i + 1][j], mp[i + 1][j + 1]) ;
		}
	}
	cout << mp[1][1];

	return 0;
}