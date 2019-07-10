#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
// 有 n 个无区别的物品 , 将他们分成 不超过 m 堆， 问有多少种分法 ？

// d[i][j] 表示将数字i分成j份的方案数（初始化d[0][j] = 1)，有2种类型：
// 1.带0的划分可以少一份。如4 = 0 + 2 + 2 = 2 + 2，把4分成3份 = 把4分成2份
// 即把i分成j份 = 把i分成j-1份。所以d[i][j] 包含 d[i][j-1]
// 2.不带0的划分，推到带0的划分上，每份均摊少一个1。
// 如 5 = 1 + 2 + 2，与 5-3 = 1-1 + 2-1 + 2-1 => 2 = 0 + 1 + 1的效果相同
// 即把i分成j份 = 把 i - j 分成j份（每份均摊一个1）。所以d[i][j]包含d[i-j][j]
// 每个数只有这两种划分方法，综上，d[i][j] = d[i-1][j-1] + d[i-j][j]

int main() {
	int n,m;
	int d[MAXN][MAXM];
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(i>=j) d[i][j] = d[i-1][j-1] + d[i-j][j];
			else d[i][j] = d[i][j-1];//份数比数字大，可以降
		}
	}

	return 0;
}