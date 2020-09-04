//注意不连通的条件
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
//最大生成树，把权重变负，kruskal
//无法连接两个点输出-1（生成树的边数e＜v-1）

const int MAXV = 1005;
const int MAXE = 20005;

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

};

vector<edge> edges;
void addEdge(const int &f, const int &t, const int &cost) {
	edges.push_back(edge(f, t, cost));
}


bool cmp(const edge &e1, const edge &e2) {
	return e1.cost < e2.cost;
}

//v:顶点数
int kruskal(int v) {
	int cnt = 1;
	sort(edges.begin(), edges.end(), cmp);//按权重排序
	init(v);
	int res = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (unite(edges[i].from, edges[i].to)) {//unite成功，不在一个集合里
			res += edges[i].cost;
			cnt++;//每加一条边就多一个点
		}
	}
	if (cnt != v) return -1;
	return -res;
}


int main() {
	int v, m;
	cin >> v >> m;
	for (int i = 1;i <= m;i++) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		addEdge(x, y, -c);
		addEdge(y, x, -c);
		
	}
	
	cout << kruskal(v) << endl;

	return 0;
}
