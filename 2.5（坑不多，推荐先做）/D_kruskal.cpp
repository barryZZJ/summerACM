#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

//最小生成树问题，Kruskal
//注意输入，一行超过80个字符会换行

const int MAXV = 105;
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
	sort(edges.begin(), edges.end(), cmp);//按权重排序
	init(v);
	int res = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (unite(edges[i].from, edges[i].to))//unite成功，不在一个集合里
			res += edges[i].cost;
	}
	return res;
}


int main() {

	int v;
	while (cin >> v) {
		edges.clear();
		for (int i = 1;i <= v;i++) {
			for (int j = 1;j <= v;j++) {
				int c;
				scanf("%d", &c);
				if (i != j) {
					addEdge(i, j, c);
					addEdge(j, i, c);
				}
			}
		}

		cout << kruskal(v)<<endl;
		
		
	}
	return 0;
}
