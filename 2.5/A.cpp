#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>
#include <numeric>

using namespace std;

//求min(sum(d[i][])/n) * 100
//即求任意两点间最小距离，对每个点的d求和，求这些和中的最小值
//Floyd
const int MAXV = 305;
const int INF = 99999999;
int d[MAXV][MAXV];
int cows[MAXV];

int main() {
	int v, m;
	cin >> v >> m;

	for (int i = 1; i <= v;i++) {
		for (int j = 1;j <= v;j++) {
			if (i == j) d[i][i] = 0;
			else d[i][j] = INF;
		}
	}
	for (int i = 0;i < m;i++) {
		int num;
		scanf("%d", &num);
		
		for (int j = 1; j <= num; j++) {
			scanf("%d", &cows[j]);
		}
		for (int j = 1; j <= num;j++) {
			for (int k = j + 1;k <= num;k++) {
				d[cows[j]][cows[k]] = 1;
				d[cows[k]][cows[j]] = 1;
			}
		}
	}

	for (int k = 1;k <= v;k++)
		for (int i = 1;i <= v;i++)
			for (int j = 1;j <= v;j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int mind = 0;
	mind = accumulate(d[1] + 1, d[1] + v + 1, mind);
	for (int i = 2;i <= v;i++) {
		int tmp = 0;
		tmp = accumulate(d[i] + 1, d[i] + v + 1, tmp);
		mind = min(mind, tmp);
	}
	cout << 100*mind/(v-1) << endl;

	return 0;
}