#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
//d[i][j]表示第i分钟走了j次能得到的苹果总量
//上一次没走：d[i][j] = d[i-1][j] + 当前树掉不掉苹果
//上一次走了：d[i][j] = d[i-1][j-1] + 当前树掉不掉苹果
//d[i][j] = max(d[i-1][j], d[i-1][j-1]) + 苹果
//初始化：d[0][x] = 0;
//j为偶数：在1树下，j为奇数：在2树下

const int MAXT = 1005;
const int MAXW = 35;
int d[MAXT][MAXW];
int aps[MAXT];
int ans = 0;

int main() {
	int t, w;
	cin >> t >> w;

	for (int j = 0; j <= w; j++) d[0][j] = 0;

	for (int i = 1;i <= t;i++) scanf("%d", &aps[i]);

	int tmp2, apple;
	
	for (int i = 1; i <= t;i++) {
		for (int j = 0;j <= w;j++) {
			if (j == 0) tmp2 = 0;
			else tmp2 = d[i - 1][j - 1];
			if (j % 2 == 0) {
				//1树
				apple = aps[i] == 1 ? 1 : 0;
			}
			else {
				//2树
				apple = aps[i] == 2 ? 1 : 0;
			}
			d[i][j] = max(d[i - 1][j], tmp2) + apple;
			if (d[i][j] > ans) ans = d[i][j];
		}
	}
	cout << ans;
	

	return 0;
}