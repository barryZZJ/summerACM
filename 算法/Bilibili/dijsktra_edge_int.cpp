//也可以不存d[]，存每一个点的父节点，求d的时候回溯
//点编号为数字， 用edge结构体存边
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;


const int MAXN = 100;//总共点的个数范围

struct edge
{
	int to;
	int dist;
	edge(int _to, int _d) :to(_to), dist(_d) {};
};

vector<edge> g[MAXN];//第i个点的相连边

int d[MAXN];

struct cmp
{
	bool operator()(const int &s1, const int &s2) {
		return d[s1] > d[s2];
	}
};


bool seen[MAXN];
const int INF = 100000;

priority_queue<int, vector<int>, cmp> pq;

void addEdge(const int &f, const int &t, const int &cost) {
	g[f].push_back(edge(t, cost));
}

int main() {

	g[1].push_back(edge(2, 5));	g[1].push_back(edge(3, 1));
	g[2].push_back(edge(1, 5));	g[2].push_back(edge(3, 2));	g[2].push_back(edge(4, 1));
	g[3].push_back(edge(1, 1));	g[3].push_back(edge(2, 2));	g[3].push_back(edge(4, 4));	g[3].push_back(edge(5, 8));
	g[4].push_back(edge(2, 1));	g[4].push_back(edge(3, 4));	g[4].push_back(edge(5, 3));	g[4].push_back(edge(6, 6));
	g[5].push_back(edge(3, 8));	g[5].push_back(edge(4, 3));
	g[6].push_back(edge(4, 6));

	int start = 2;
	int n = 6;
	fill(d + 1, d + 1 + n, INF);
	d[start] = 0;

	fill(seen + 1, seen + n + 1, false);

	pq.push(start);
	while (pq.size()) {
		int tn = pq.top(); pq.pop();
		seen[tn] = true;
		for (int i = 0;i < g[tn].size();i++) {
			//g[tn][i]当前点相连边 g[tn][i].to为邻接点
			int adj = g[tn][i].to;
			int distance = g[tn][i].dist;
			if (!seen[adj]) {
				d[adj] = min(d[adj], d[tn] + distance);
				pq.push(adj);
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		cout << start << "->" << i << " : " << d[i] << endl;
	}

}
