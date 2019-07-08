#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

//虚点并查集
//对于一个人a，建两个点a和a+n。
//a + n实际上并不存在，只起到连接的作用，是一个虚点。
//所有与a相连的点都是a的同伙。
//所有与a + n相连的点都是a的敌人。
//敌人的敌人是同伙

//默认x，y都是a帮派，
//如果x和y是敌人，则合并(x, y + n)和(y, x + n)，要么x∈a，y∈b要么x∈b，y∈a

//两个数在同一集合里代表这两个情况同时成立或同时不成立

//判断的时候，如果(x,y+n) || (y,x+n)在同一个集合，代表x,y不在同一个帮派
//如果(x,y) || (x+n, y+n)代表x,y在同一个帮派

const int MAXV = 100005*2;

int p[MAXV];
int root(int x) {
	if (x == p[x]) return x;
	int rootx = p[x];
	while (rootx != p[rootx]) {
		rootx = p[rootx];
	}
	return p[x] = rootx;
}
bool same(int x, int y) {
	return root(x) == root(y);
}
void unite(int x, int y) {
	x = root(x); y = root(y);
	if (x != y)
		p[x] = y;
}

int main() {
	int T;
	cin >> T;
	int v, m;
	char s[2];
	int x, y;
	while (T--) {
		scanf("%d%d", &v, &m);
		for (int i = 1;i <= v*2;i++) p[i] = i;
		for (int i = 1;i <= m;i++) {
			scanf("%s %d%d", &s, &x, &y);
			if (s[0] == 'D') {
				unite(x, y + v);
				unite(y, x + v);
			}
			else {
				
				if (same(x, y) || same(x + v, y + v)) cout << "In the same gang." << endl;
				else if (same(x, y + v) || same(y, x + v)) cout << "In different gangs." << endl;
				else cout << "Not sure yet." << endl;
				
			}
		}
	}

	return 0;
}