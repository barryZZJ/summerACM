//最大生成森林问题，Kruskal
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

//并查集用来找环
const int MAXN = 50005;
int p[MAXN];

//默认一开始所有点都是独立的
void init(int n) {
	for (int i = 0; i <= n; i++) {
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

};

vector<edge> edges;

bool cmp(const edge &e1, const edge &e2) {
	return e1.cost < e2.cost;
}

//n:顶点数
int kruskal(int n) {
	sort(edges.begin(), edges.end(), cmp); //按权重排序
	init(n);
	int res = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (unite(edges[i].from, edges[i].to))//unite成功，不在一个集合里
			res += edges[i].cost;
	}
	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		int n;//R条边
		scanf("%d%d%d", &N, &M, &n);
		int male, female, d;
		for (int i = 0;i < n;i++) {
			scanf("%d%d%d", &male, &female, &d);
			//男点编号N, 女点编号M+MAXN
			edges.push_back(edge(male, female + N, -d));//本身求的是最小权，加负号变求出来的是绝对值最大
		}
		//kruskal结果是负数
		cout << 10000*(N+M) + kruskal(n + 2) << endl;
		edges.clear();

	}
	return 0;
}