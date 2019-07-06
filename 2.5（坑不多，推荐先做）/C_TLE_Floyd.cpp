//Floyd爆时间，改用两次spfa
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;
//单向边
//起点i，终点x
//求max(d[i][x] + d[x][i])
//求任意点间最短距离，Floyd


const int INF = 999999999;
const int MAXV = 1005;
int d[MAXV][MAXV];

int main() {
	int v, m, x;
	cin >> v >> m >> x;

	for (int i = 1;i <= v;i++) {
		for (int j = 1;j <= v;j++) {
			if (i == j) d[i][i] = 0;
			else d[i][j] = INF;
		}
	}

	for (int e = 0; e < m;e++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		d[u][v] = c;
	}

	for (int k = 1;k <= v;k++)
		for (int i = 1;i <= v;i++)
			for (int j = 1;j <= v;j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	int ans = d[1][x] + d[x][1];
	for (int k = 2;k <= v;k++) {
		ans = max(ans, d[k][x] + d[x][k]);
	}
	cout << ans;

	return 0;
}