#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

//有m个时间段，第i个时间段从l[i]到r[i]能产e[i]的奶，
//产完要休息R，问N小时总共能产多少奶
//初始化d[0] = 0;
//d[i]表示第i个时间段结束时最多能产多少奶
//能产：令max =  之前所有产的d[j]中最大的那一个 
//d[i] = max + e[i]
//不能产：之前所有时间都不能产，从hs[i]开始产第一次奶。max = 0; d[i]= 0 + e[i]
//综上d[i]=max + e[i]
//时间段按起始时间顺序排序

//const int MAXN = 1000005;
const int MAXM = 1005;

struct Hour {
	int l, r, e;
}hs[MAXM];

bool cmp(Hour h1, Hour h2) {
	//if (h1.l == h2.l) return h1.r < h2.r;
	return h1.l < h2.l;
}

int d[MAXM];


int main() {
	int n, m, R;
	cin >> n >> m >> R;
	for (int i = 1;i <= m;i++) scanf("%d%d%d", &hs[i].l, &hs[i].r, &hs[i].e);
	sort(hs + 1, hs + 1 + m, cmp);
	for (int i = 1;i <= m;i++) d[i] = 0;

	int maxn = 0;//i之前产得最多的

	int ans = 0;
	for (int i = 1;i <= m;i++) {
		
		maxn = 0;//假设不能产，之前产得最多的就是0
		for (int j = 1;j < i;j++) {
			if (hs[j].r + R <= hs[i].l) {
				maxn = max(d[j], maxn);
			}
		}
		d[i] = maxn + hs[i].e;
		
		
		ans = max(ans,d[i]);
	}
	
	cout << ans;
	return 0;
}