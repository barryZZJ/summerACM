#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>

//并查集
//x+A,y+A 代表x,y是A
//x+B,y+B 代表x,y是B
//x+C,y+C 代表x,y是C
//1.如果x和y同类, 
//	先判断集合中是否存在 （x吃y）或（y吃x）的关系
//  即是否有 same(x+A,y+B)或same(x+B,y+A)（因为是A、B、C是等价的，所以只要表示出互相吃的关系都行）
//	没有的话说明要么x，y没出现过，要么已知是同类
//	则令他俩是同类，集合中加入x+A,y+A; x+B,y+B; x+C,y+C;

//2.如果x吃y,
//	先判断集合中是否存在 （x和y是同类）或（x和y差了一个等级）的关系
//	即是否有same(x+A,y+A)或same(x+A,y+C)
//	没有的话说明要么没出现过，要么已知x吃y
//	则集合中加入x+A,y+B; x+B,y+C; x+C,y+A;

using namespace std;

const int MAXN = 50005;


int p[MAXN * 3];
void init(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
}

int find(int x) {
	if (p[x] == x) return x;
	int rootx = p[x];
	while (rootx != p[rootx]) {
		rootx = p[rootx];
	}
	return p[x] = rootx;
}

bool unite(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return false;
	p[y] = x;
	return true;
}

bool same(int x, int y) {
	bool res = (find(x) == find(y));
	return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	int A = 0, B = n, C = 2 * n;

	init(3 * n);

	int d, x, y;
	int ans = 0;
	while (k--) {
		scanf("%d%d%d", &d, &x, &y);
		if (x<1 || x>n || y<1 || y>n) {
			ans++;
			continue;
		}
		if (d == 1) {
			//同类
			if (same(x + A, y + B) || same(x + B, y + A)) {
				ans++;
				continue;
			}
			else {
				unite(x + A, y + A); unite(x + B, y + B); unite(x + C, y + C);
			}

		}

		if (d == 2) {
			//x吃y
			if (x == y) {
				ans++;
				continue;
			}
			if (same(x + A, y + A) || same(x + A, y + C)) {
				ans++;
				continue;
			}
			else {
				unite(x + A, y + B); unite(x + B, y + C); unite(x + C, y + A);
			}

		}

	}

	printf("%d", ans);

	return 0;
}