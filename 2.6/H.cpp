#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
//H-number是所有4n+1的数(n>=0)
//接下来只在H-number范围内讨论
//H-prime是只有1xh没有别的因子的数，即H素数
//H-composite是H和数
//H-semi-primes是恰能表示成两个H-prime相乘的数
//求1~h之间的H-semi-prime数
const int MAXN = 1000005;
int seen[MAXN];
int ans[MAXN];

int main() {
	for (int i = 5;i <= MAXN;i+=4) {
		for (int j = 5;j <= MAXN;j+=4) {
			if (i*j >= MAXN) break;
			if (seen[i]==0 && seen[j]==0) {//没有seen过就说明i、j不能表示成两个数相乘，是素数
				seen[i*j] = 1;//两个素数相乘是semi-prime
			}
			else {
				seen[i*j] = -1;//这个数不是素数，不能用
			}
		}
	}
	int cnt = 0;
	for (int i = 1;i <= MAXN;i+=4) {
		if (seen[i]==1) cnt++;
		ans[i] = cnt;
	}
	int h;
	while (~scanf("%d", &h)) {
		if (!h) break;
		printf("%d %d\n", h, ans[h]);
	}

	return 0;
}