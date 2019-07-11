#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <map>

using namespace std;
//由N个字母组成的长度为M的字符串（小写）
//字符串 s
//字母 增加该字母的cost 删除该字母的cost
//求最少cost让s变为回文（可以是空字符串）

//先构造出可能的回文选项，字符串跟回文的字符串比较差哪些字符（LCS最长公共子序列）
//因此要求如何让字符串变回文

//d[i][j]表示区间i到j变成回文的cost， [i, j]表示从区间i到j的字符串

//如果s[i] == s[j],dp[i][j] = d[i+1][j-1]

//如果 [i+1, j] 是回文的那么把[i,j]变成回文可以: 1)前删第i个字符变成[i+1,j]； 2)后加第i个字符 [i+1,j] + s[i]
//d[i][j] = d[i + 1][j] + min(add[s[i]]，del[s[i]])

//如果 [i,j-1] 是回文的那么把[i,j]变回文可以: 1)后删第j个字符变成[i,j-1]； 2)前加第j个字符 s[j] + [i+1,j]
//d[i][j] = d[i][j-1] + min(add[s[j]], del[s[j]])

const int MAXN = 2005;
//const int INF = 1 << 30;
int d[MAXN][MAXN];

char s[MAXN], t[2];

//map<char, int> add;
//map<char, int> del;
map<char, int> mincost;

int main() {
	int n, m;
	cin >> n >> m >> s;
	int ad, de;
	for (int i = 1; i <= n; i++) {
		scanf("%s%d%d", &t, &ad, &de);
		/*add[t[0]] = ad;
		del[t[0]] = de;*/
		mincost[t[0]] = min(ad, de);
	}
	//for (int i = 1; i <=n ;i++) {
	//	for (int j = 1; j <= n;j++) {
	//		if (i == j)d[i][i] = 0;
	//		else d[i][j] = INF;
	//	}
	//}

	for (int i =m-1 ;i >= 0;i--) {
		for (int j = i + 1; j < m;j++) {
			d[i][j] = min((d[i + 1][j] + mincost[s[i]]), d[i][j - 1] + mincost[s[j]]);
			if (s[i] == s[j]) 
				d[i][j] = min(d[i + 1][j - 1], d[i][j]);
		}
	}

	cout << d[0][m-1];
	


	return 0;
}