//1.优先不加油。
//2.用优先队列。把已经过的加油站加到优先队列中
//2.没油的时候优先取 已经过的加油站中 油最多加油站（优先队列的顶元素），再往前走直到下一次没油
//  看能不能到终点或到下一个加油站，能到就继续走，不能就-1

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 10005;
const int MAXF = 1000005;
struct P {
	int d;
	int f;
	//bool passed;
} p[MAXN], car;


bool cmpd(const P &p1, const P &p2) {
	return p1.d < p2.d;
}

struct cmpf {
	bool operator ()(const P &p1, const P &p2) {
		return p1.f < p2.f;
	}
};

priority_queue<P, vector<P>, cmpf> pq;


int main() {

	int n;
	cin >> n;

	p[0].d = 0; p[0].f = 0; //p[0].passed = false; //终点也当作加油站
	for (int i = 1;i <= n;i++) {
		scanf("%d%d", &p[i].d, &p[i].f);
		//p[i].passed = false;
	}
	scanf("%d%d", &car.d, &car.f);

	//把加油站按照离终点的距离升序排列（越靠前的越接近终点）
	sort(p + 1, p + n + 1, cmpd);

	int index = n;//最后经过的加油站的角标
	int ans = 0;
	while (car.d--) {//一次走一步  ， todo也可以按加油站循环，一次走一个加油站
		car.f--;

		if (car.d == p[index].d) {
			if (index == 0) {
				//到终点了
				break;
			}
			//经过加油站，计入
			pq.push(p[index]);
			index--;
		}

		if (car.f == 0) {
			//没油了要从pq中取加油站的油
			if (pq.empty()) {
				//没油取了
				ans = -1;
				break;
			}
			else {
				car.f += pq.top().f; pq.pop();
				ans++;
			}
		}

	}

	printf("%d", ans);


	return 0;
}