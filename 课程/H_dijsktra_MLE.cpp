//MLE 报错
//dijsktra 

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <climits>

//求次短路：
//法(1)在Dijsktra的时候第一次出堆不seen，第二次出堆再seen，第二次出堆一定是次短路，找目的地(n)的次短路距离即可
//法(2)求1,k的最短距离和k,n的最短距离；遍历边，如果带这条边的路是 非最短路中 最短的 就是次短路
//	 1,n的次短距离等于min(d(1,k) + d(k,n)) 且 > d(1,n)
//MDZZ:如果只有一条路需要往回跑一个点再去

using namespace std;
const int MAXN = 5005;

//(2)
struct edge
{
	int to;
	int dist;
	edge(int _to, int _d) :to(_to), dist(_d) {};
};

int d1[MAXN], d2[MAXN];

vector<edge> g[MAXN];//第i个点的相连边
//vector<edge> E[MAXN];//所有单向边
vector<edge>::iterator it;


struct cmp1
{
	bool operator()(const int &s1, const int &s2) {
		return d1[s1] > d1[s2];
	}
};

struct cmp2
{
	bool operator()(const int &s1, const int &s2) {
		return d2[s1] > d2[s2];
	}
};

bool seen[MAXN];
const int INF = INT_MAX;



int main() {
	int n, r; // n个点r条边
	cin >> n >> r;
	for (int i = 1;i <= r; i++) {
		int n1, n2, dist;
		scanf("%d%d%d", &n1, &n2, &dist);
		g[n1].push_back(edge(n2, dist));
		g[n2].push_back(edge(n1, dist));

		//E[n1].push_back(edge(n2, dist));

	}

	if (n == 1) {
		cout << "0" << endl;
		return 0;
	}



	fill(d1 + 1, d1 + 1 + n, INF);
	d1[1] = 0;

	fill(seen + 1, seen + n + 1, false);

	priority_queue<int, vector<int>, cmp1> pq;

	pq.push(1);
	while (pq.size()) {
		int tn = pq.top(); pq.pop();
		seen[tn] = true;
		for (it = g[tn].begin(); it != g[tn].end(); it++) {
			//g[n][i]当前点相连边 g[n][i].to为邻接点
			int adj = it->to;
			int distance = it->dist;
			if (!seen[adj]) {
				d1[adj] = min(d1[adj], d1[tn] + distance);
				pq.push(adj);
			}
		}

	}


	priority_queue<int, vector<int>, cmp2> pq2;

	fill(d2 + 1, d2 + 1 + n, INF);
	d2[n] = 0;

	fill(seen + 1, seen + n + 1, false);

	while (!pq2.empty()) pq2.pop();

	pq2.push(n);
	while (pq2.size()) {
		int tn = pq2.top(); pq2.pop();
		seen[tn] = true;
		for (it = g[tn].begin(); it != g[tn].end(); it++) {
			//g[n][i]当前点相连边 g[n][i].to为邻接点
			int adj = it->to;
			int distance = it->dist;
			if (!seen[adj]) {
				d2[adj] = min(d2[adj], d2[tn] + distance);
				pq2.push(adj);
			}
		}

	}

	//d1[]为所有点到起点的最短距离， d2[]为到终点的最短距离
	int mind = d1[n];
	int min2d = INF;
	int tmp = INF;

	for (int k = 1; k <= n; k++) {
		for (it = g[k].begin(); it != g[k].end(); it++) {
		//for (it = E[k].begin(); it != E[k].end(); it++) {
			//E[k]是当前点的所有相连边
			edge e = *it;
			int u = k, v = e.to;
			if (d1[u] + e.dist + d2[v]<min2d && d1[u] + e.dist + d2[v]>mind)
				min2d = d1[u] + e.dist + d2[v];
		}
	}
	if (min2d == INF) {
		//只有最短路没有次短路，强行构造次短路
		//加上终点相连边距离的2倍
		min2d = mind + 2 * g[n][0].dist;
	}
	cout << min2d << endl;
	return 0;
}

