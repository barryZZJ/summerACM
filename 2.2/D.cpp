//注意多组数据
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
//1，第一天的奶酪只能当天生产，这是无法贪心选取的，暂时假设以后的奶酪全在这一天生产

//2，第二天的话，就要考虑是前一天生产存放到第二天还是第二天再生产呢？这就需要比较了
// 如果当天生产比较省钱，那么就当天生产！而且假设以后的所有奶酪都在这天生产的！
// 否则就是前一天屯够今后所有的

//实现：
//第一天一定要生产，而且第一天是目前最便宜那一天, k = 1;假设这一天生产后面的每一天
//设 第i天产价c[i] 和 之前最便宜那天k带利到第i天的实际产价c2(i) = c[k]+(i-k)*s
//比较 第i天产价C(i) 和 c2[i]， 哪个小就让哪个生产，更新最便宜的天编号k = k或i
//而且对于后面的那些天来说，到第i+m天的c2[i+m] =（c[x]+(i+m -x)*s）中的x应该是i+m之前最便宜那一天
const int MAXN = 10005;
int c[MAXN], y;

int main() {
	int n, s;
	while (cin >> n >> s) {//注意多组数据
		long long ans=0;
		scanf("%d%d", &c[1], &y);
		ans += c[1] * y;
		int k = 1;//最便宜的天数
		int c2 = c[1];

		for (int i = 2; i <= n;i++) {
			scanf("%d%d", &c[i], &y);
			c2 = c[k] + (i - k)*s;
			int tc = c2;
			if (c[i] < c2) {
				tc = c[i];
				k = i;
			}
			//cout << "day " << i << " cost " << tc <<" x "<< y << endl;

			ans += tc * y;
		}
		cout << ans << endl;
		

	}

	return 0;
}