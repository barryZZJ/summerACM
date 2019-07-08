//注意有多组数据
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

//在满足minspf的条件下，将每一种防晒霜优先涂到maxspf小的奶牛身上，因为maxspf大的奶牛有更多的选择。
//这里就需要一个优先队列来储存满足minspf的奶牛的maxspf的值。

//1.将奶牛按照minspf升序排列，将防晒霜按照spf升序排列。
//2.枚举防晒霜，将minspf <= spf的奶牛的maxspf存到优先队列中，然后值小的先出队列，看是够不够涂（num>0）+能不能涂（maxspf >= spf)，不满足这头牛就废了。

const int MAXN = 2505;

struct range {
	int ls, rs;
}cows[MAXN];

struct lot
{
	int spf, num;
}los[MAXN];

bool cmp(range r1, range r2) {
	if (r1.ls == r2.ls) return r1.rs < r2.rs;
	return r1.ls < r2.ls;
}

bool cmp2(lot l1, lot l2) {
	return l1.spf < l2.spf;
}


priority_queue<int, vector<int>, greater<int> > pq;


int main() {
	int n, l;
	while (cin >> n >> l) {
		//int mi, ma;
		for (int i = 1;i <= n;i++) {
			cin >> cows[i].ls >> cows[i].rs;
		}
		for (int i = 1;i <= l;i++) {
			cin >> los[i].spf >> los[i].num;
		}
		sort(cows + 1, cows + 1 + n, cmp);
		sort(los + 1, los + 1 + l, cmp2);
		int ans = 0;
		int j = 1;
		for (int i = 1;i <= l;i++) {
			while (j <= n && cows[j].ls <= los[i].spf) {
				pq.push(cows[j].rs);
				j++;
			}

			while (!pq.empty() && los[i].num) {
				int tmp = pq.top(); pq.pop();
				if (los[i].spf <= tmp) {
					los[i].num--;
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}


