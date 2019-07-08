#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
//N种面值，每周付C元
//最多可以付多少周
//面值， 个数
//对于面值小于c的硬币。要使用的周数最多我们应该就要使钱的利用率最大。
//也就是说损失的钱最少。尽量不要超过c太多。
//在不超过c的情况下对于大面值和小面值的优先使用大面值的。
//因为小面值的组合可得到大面值的(整除关系)。留下小面值的给后面的组合最优的可能性越大。
//如这种策略下没凑够c的话就找一个最小的面额。使得组合值大于c。(使损失值最小)
//1.先给面值超过C的
//2.面值不到C的，先用最大的面值凑，尽量靠近C（但小于C），剩下的钱用小的面值补

const int MAXN = 25;

struct coin
{
	ll m, num;
}coins[MAXN];//第i种面值

bool cmp(coin c1, coin c2) {
	return c1.m < c2.m;
}

int main() {
	int n, c;
	while (cin >> n >> c) {
		for (int i = 1;i <= n;i++) {
			scanf("%lld%lld", &coins[i].m, &coins[i].num);
		}
		sort(coins + 1, coins + 1 + n, cmp);

		ll ans = 0;

		for (int i = n; i >= 1;i--) {
			if (coins[i].m >= c) {
				ans += coins[i].num;
				coins[i].num = 0;
			}
			else {
				break;
			}
		}

		ll use[MAXN];//第i种面额用了几张
		bool flag;//钱够不够
		
		while (true) {
			ll tempc = c;//当天剩的钱
			flag = false;
			fill(use + 1, use + 1 + n, 0);
			for (int i = n; i >= 1; i--) {
				if (coins[i].num) {
					ll num = tempc / coins[i].m;//所有大钱靠近C最多需要几张（向下取整）
					num = min(num, coins[i].num);//实际有几张
					tempc -= num * coins[i].m; //还剩多少钱
					use[i] = num; 
					if (tempc == 0) {
						flag = true;//正好够，续一天
						//ans++;
						break;
					}
				}
			}
			if (tempc > 0) {
				for (int i = 1; i <= n;i++) {
					while (coins[i].num > use[i]) {
						//还有小钱可以用，一直加小钱直到凑够
						tempc -= coins[i].m;
						use[i]++;
						if (tempc <= 0) {
							flag = true;//够了，续
							//ans++;
							break;
						}
					}

					if (flag) break;
				}
			}
			if (!flag) break;//不够下一天的了，退出

			ll days = LLONG_MAX;//够续多少天全算出来
			for (int i = 1;i <= n;i++) {
				if (use[i])
					days = min(days, coins[i].num / use[i]);//够续的天数全算出来
			}
			ans += days;
			for (int i = 1;i <= n;i++) {
				coins[i].num -= use[i] * days;//够续的都用了，看最后还剩不剩
			}
		}
		

		cout << ans << endl;

	}

	return 0;
}