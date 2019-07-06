#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <climits>
#include <vector>


using namespace std;

//求max(任意两个点之间最小距离)
//即求最小生成树上最长的边（kruskal）
const int MAXV = 2005;
const int MAXE = 10005;
const int INF = INT_MAX;

struct edge
{
	int from, to, cost;
	edge(int f = 0, int t = 0, int c = 0) :from(f), to(t), cost(c) {};
};
vector<edge> edges;
vector<edge>::iterator it;
//并查集---
int p[MAXV];
void init(int v) {
	for (int i = 1;i <= v;i++)
		p[i] = i;
}
int root(int x) {
	if (x == p[x]) return x;
	int root = x;
	while (root != p[root]) {
		root = p[root];
	}
	return p[x] = root;
}
bool unite(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	p[y] = x;
	return true;
}
//---

bool cmp(const edge &e1, const edge &e2) {
	return e1.cost < e2.cost;
}

int kruskal(int e) {
	int maxe=0;
	for (it = edges.begin(); it != edges.end(); it++) {
		if (unite(it->from, it->to)) maxe = max(maxe, it->cost);
	}
	return maxe;
}

int main() {
	int v, e;
	cin >> v >> e;

	for (int i = 0;i < e;i++) {
		int f, t, c;
		scanf("%d%d%d", &f, &t, &c);
		edges.push_back(edge(f, t, c));
	}
	sort(edges.begin(), edges.end(), cmp);

	init(v);
	cout << kruskal(e) << endl;


	return 0;
}