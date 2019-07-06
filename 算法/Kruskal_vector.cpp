//不连通的条件：e != v-1
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

//并查集用来找环
const int MAXV = 10005;
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

};//edges[MAXE];
vector<edge> edges;

bool cmp(const edge &e1, const edge &e2) {
	return e1.cost < e2.cost;
}

//v:顶点数
int kruskal(int v) {
	sort(edges.begin(), edges.end(), cmp);//按权重排序
	init(v);
	int res = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (unite(edges[i].from, edges[i].to))//unite成功，不在一个集合里
			res += edges[i].cost;
	}
	return res;
}

void addEdge(const int &f, const int &t, const int &cost) {
	edges.push_back(edge(f, t, cost));
}

int main() {
	int v;//顶点数
	//int e;//边数

	//初始化边数组----
	v = 5;
	//单向边就行
	edges.push_back(edge(1, 2, 1));
	edges.push_back(edge(1, 3, 2));
	edges.push_back(edge(1, 5, 4));
	edges.push_back(edge(2, 3, 1));
	edges.push_back(edge(3, 5, 6));
	edges.push_back(edge(2, 4, 2));
	edges.push_back(edge(3, 4, 3));
	edges.push_back(edge(4, 5, 5));
	//----
    
	int res = kruskal(v+5);


	cout << "最小生成树权重=" << res;

	return 0;
}