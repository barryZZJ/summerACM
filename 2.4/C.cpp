#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

//并查集
//能通信的电脑放在一个集合里

//N台电脑，两台电脑距离<=D或能跟另一台电脑通信则这两台电脑可以通信。
//能通信的电脑放在一个集合里，判断在不在一个集合里就知道能不能通信

//实现：
//修哪台哪台就亮。每修一个就遍历已经亮的电脑中，能通信的电脑放在一个集合里
//判断的时候看这两台电脑 在同一个集合 则可以通信，否则不行
const int MAXV = 1010;

int p[MAXV];
void init(int n) {
	for (int i = 1;i <= n;i++) p[i] = i;
}
int root(int x) {
	if (x == p[x]) return x;
	return p[x] = root(p[x]);
}
bool same(int x, int y) {
	x = root(x); y = root(y);
	return x == y;
}
bool unite(int x, int y) {
	x = root(x); y = root(y);
	if (x == y)return false;
	p[x] = y;
	return true;
}

struct P {
	int x, y;
}nodes[MAXV];


bool neighbor(const P &p1, const P &p2, int &d) {
	int dx = p1.x - p2.x, dy = p1.y - p2.y;
	return dx * dx + dy * dy <= d * d;
}

bool seen[MAXV];

int main() {
	int n, d;
	cin >> n >> d;
	init(n);
	for (int i = 1;i <= n;i++) {
		cin >> nodes[i].x >> nodes[i].y;
	}
	char s[2];
	while (~scanf("%s", &s)) {
		int x, y;
		if (s[0] == 'O') {
			cin >> x;
			if (seen[x]) continue;
			seen[x] = true;

			for (int i = 1;i <= n;i++) {
				if (i == x)continue;
				if (seen[i] && neighbor(nodes[i], nodes[x], d)) unite(x, i);
			}

		}
		else {
			cin >> x >> y;
			if (same(x, y)) cout << "SUCCESS" << endl;
			else cout << "FAIL" << endl;
		}
	}
	


	return 0;
}