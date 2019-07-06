#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

//并查集用来找环
const int MAXV = 10005;
const int MAXE = 20000;
int p[MAXV];

//默认一开始所有点都是独立的
void init(int v) {
	for (int i = 0; i <= v; i++) {
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

bool same(int x, int y) {
	return find(x) == find(y);
}

bool unite(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return false;
	p[x] = y;
	return true;
}

struct edge
{
	int from;
	int to;
	int cost;

	edge(int f = 0, int t = 0, int c = 0) :from(f), to(t), cost(c) {};

}edges[MAXE];

bool cmp(const edge &e1, const edge &e2) {
	return e1.cost < e2.cost;
}

//v:顶点数, e:边数
int kruskal(int v, int e) {
	sort(edges + 1, edges + 1 + v, cmp); //按权重排序
	init(v);
	int res = 0;
	for (int i = 1; i <= e; i++) {
		if (unite(edges[i].from, edges[i].to))//unite成功，不在一个集合里
			res += edges[i].cost;
	}
	return res;
}

int main() {
	int v;//顶点数
	int e;//边数
	
	//初始化边数组----
	v = 5;
	e = 8;
	//单向边就行
	edges[1] = edge(1, 2, 1); //edges[9] = edge(2, 1, 1);
	edges[2] = edge(1, 3, 2); //edges[10] = edge(3, 1, 2);
	edges[3] = edge(1, 5, 4); //edges[11] = edge(5, 1, 4);
	edges[4] = edge(2, 3, 1); //edges[12] = edge(3, 2, 1);
	edges[5] = edge(3, 5, 6); //edges[13] = edge(5, 3, 6);
	edges[6] = edge(2, 4, 2); //edges[14] = edge(4, 2, 2);
	edges[7] = edge(3, 4, 3); //edges[15] = edge(4, 3, 3);
	edges[8] = edge(4, 5, 5); //edges[16] = edge(5, 4, 5);
	//----

	int res = kruskal(v, e);


	cout << "最小生成树权重=" << res;

	return 0;
}