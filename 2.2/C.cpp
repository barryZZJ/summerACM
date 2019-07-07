#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
const int MAXN = 50010;
struct P
{
	int l, r;
	int index;
	//int stall;
}p[MAXN];

bool cmp(const P &p1, const P &p2) {
	if (p1.l == p2.l)return p1.r < p2.r;
	return p1.l < p2.l;
}

struct cmps
{
	bool operator()(const P &p1, const P &p2) {
		if (p1.r == p2.r) return p1.l < p2.l;
		return p1.r > p2.r;
	}
};

priority_queue<P,vector<P>,cmps> lps;//所有stall里的最后一头牛

int order[MAXN];//第i头牛的stall


//没有重叠时间的牛可以放到同一个stall里
//所有的牛按开始时间升序排序
//贪心放在每个stall里最后一头牛中结束时间早的牛的后面
//所以用pq存所有stall里最后一头牛，结束时间早的优先被取出
//按开始时间顺序取牛，与pq按优先级遍历出的牛比较，
//不重叠就共用stall，这个stall的最后一头牛就更新
//重叠的话一定跟别的都重叠，stall就+1
int main() {
	int n;
	while (cin >> n) {

		for (int i = 1; i <= n;i++) {
			scanf("%d%d", &p[i].l, &p[i].r);
			p[i].index = i;
		}
		sort(p + 1, p + 1 + n, cmp);

		fill(order + 1, order + 1 + n, 0);
	
		int maxstall = 1;
		//p[1].stall = 1;
		lps.push(p[1]);
		order[p[1].index] = 1;

		for (int i = 2; i <= n;i++) {

			if (p[i].l <= lps.top().r) {
				//重叠，新开一个stall
				maxstall++;
				//p[i].stall = maxstall;
				order[p[i].index] = maxstall;
			}
			else {
				//不重叠就共用
				order[p[i].index] = order[lps.top().index];
				lps.pop();
			}

			lps.push(p[i]);
			
		}
		printf("%d\n", maxstall);
		//cout << maxstall << endl;
		for (int j = 1; j <= n; j++) {
			printf("%d\n", order[j]);
			//cout << order[j] << endl;
		}
		while (lps.size()) lps.pop();
	}

	return 0;
}