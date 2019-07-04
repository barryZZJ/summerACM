//最小覆盖问题
//用最少的牛覆盖总时间

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
struct W {
	int st;
	int ed;
};
bool operator <(const W &w1, const W &w2) {
	if (w1.st == w2.st) return w1.ed > w2.ed;
	return w1.st < w2.st;
}
const int MAXN = 26000, MAXT = 1000005;


//思路：1.时间从1到T递增，选当前时间在工作时间内的牛中结束时间最晚的2.直到上一头牛结束后再选下一头牛
int main() {
	int n, t;
	scanf("%d%d", &n, &t);
	W w[26000];
	for (int i = 0;i < n;i++) {
		scanf("%d%d", &w[i].st, &w[i].ed);
	}

	//牛按开始时间排序，后期只要有一个不满足条件就可以直接break
	sort(w, w + n);

	int maxed, cowi = -1;
	int flag;//是否有牛用
	bool occupy;
	occupy = false; //该小时是否有牛值班

	int ans = 0;

	//time能取到t啊，取等条件debug了一晚上。。
	for (int time = 1;time <= t;time++) {

		//这头牛是否结束了
		if (occupy && time > w[cowi].ed)
			occupy = false;
		if (!occupy) {
			flag = false;
			maxed = 0; // 所有满足条件的牛中最晚的结束时间
			//cowi = 0;//当前小时最优的牛的下标

			for (int j = cowi + 1; j < n;j++) {//这里注意j不是从0开始而是从上一头没有用过的牛开始
				//第j头牛
				if (w[j].st <= time && time <= w[j].ed) {
					if (w[j].ed > maxed) {
						//当前的牛中满足工作条件且最优的牛
						cowi = j;
						maxed = w[j].ed;
						flag = true;
					}
				}
				else{
					//没有满足条件的牛
					if (w[j].st > time) break;
					continue;
					
				}

			}

			//所有牛都看完了
			if (!flag) {
				//没有可用的牛
				ans = -1;
				break;
			}
			else {
				//就用这头牛
				ans++;
				occupy = true;
			}
		}

	}
	printf("%d", ans);



	return 0;
}