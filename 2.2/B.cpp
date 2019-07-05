
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
//0.如果有岛的y坐标大于雷达半径一定无解，否则一定有解
//1.对于每个岛有一个在x轴能放雷达的范围，求出所有岛对应的范围，按岛的x轴排序
//2.雷达应该放在（没有被覆盖的岛中）相交的范围中交集的最右端

const int MAXN = 1005;
const int INF = 99999999;


struct Range
{
	double l;
	double r;
}range[MAXN];

bool operator <(const Range &r1, const Range &r2) {
	return r1.l < r2.l;
}

void getrange(const int x, const int y, Range &range, const int &r) {
	double dx;
	if (y == r) dx = 0;
	else dx = sqrt(r*r - y*y);

	range.l = x - dx;
	range.r = x + dx;
}


int main() {
	int n;
	int r;
	int t = 1;
	while (scanf("%d%d", &n, &r) == 2) {
		if (n == 0 && r == 0) break;

		int ans = 0;

		for (int i = 0;i < n;i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (y > r) ans = -1;
			getrange(x, y, range[i], r);
			
		}
		if (ans == -1) {
			cout << "Case " << t++ << ": " << ans << endl;
			continue;
		}

		sort(range, range + n);


		double maxl = range[0].l, minr = range[0].r;

		bool flag = false; //更新了交集的端点
		
		range[n].l = INF; range[n].r = INF;

		for (int i = 0;i <= n;i++) {
			//这个岛与范围有交集
			if ( range[i].l <= minr && range[i].r >= maxl && i<n) {
				//就更新交集的左右端点
				maxl = max(maxl, range[i].l);
				minr = min(minr, range[i].r);
				flag = true;
			}
			else {
				flag = false;
			}
			if(!flag){
				ans++;
				maxl = range[i].l; minr = range[i].r;
			}
			
		}

		//if (ans == 0) ans = -1;
		cout << "Case " << t++ << ": " << ans << endl;

	}


	return 0;
}