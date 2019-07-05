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


const int MAXN = 6;//总共点的个数

struct edge
{
	int to;
	int dist;
	edge(int _to, int _d) :to(_to), dist(_d) {};
};

vector<edge> g[MAXN + 1];

int d[MAXN + 1];

struct cmp
{
	bool operator()(const int &s1, const int &s2) {
		return d[s1] > d[s2];
	}
};


bool seen[MAXN + 1];
const int INF = 10000;

priority_queue<int, vector<int>, cmp> pq;

int main() {

	g[1].push_back(edge(2, 5));	g[1].push_back(edge(3, 1));
	g[2].push_back(edge(1, 5));	g[2].push_back(edge(3, 2));	g[2].push_back(edge(4, 1));
	g[3].push_back(edge(1, 1));	g[3].push_back(edge(2, 2));	g[3].push_back(edge(4, 4));	g[3].push_back(edge(5, 8));
	g[4].push_back(edge(2, 1));	g[4].push_back(edge(3, 4));	g[4].push_back(edge(5, 3));	g[4].push_back(edge(6, 6));
	g[5].push_back(edge(3, 8));	g[5].push_back(edge(4, 3));
	g[6].push_back(edge(4, 6));

	int start = 1;
	for (int i = 1;i <= MAXN;i++) {
		if (i == start) d[i] = 0;
		else d[i] = INF;
	}

	fill(seen + 1, seen + MAXN + 1, false);

	pq.push(start);
	while (pq.size()) {
		int n = pq.top(); pq.pop();
		seen[n] = true;
		for (int i = 0;i < g[n].size();i++) {
			//g[n][i]当前点相连边 g[n][i].to为邻接点
			int adj = g[n][i].to;
			int distance = g[n][i].dist;
			if (!seen[adj]) {
				d[adj] = min(d[adj], d[n] + distance);
				pq.push(adj);
			}
		}

	}
	for (int i = 1;i <= MAXN;i++) {
		cout << i << " : " << d[i] << endl;
	}

}
