//spfa
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <climits>

//求次短路：
//spfa 求1,k的最短距离和k,n的最短距离；遍历边，如果带这条边的路是 非最短路中 最短的 就是次短路
//	 1,n的次短距离等于min(d(1,k) + d(k,n)) 且 > d(1,n)
//MDZZ:如果只有一条路需要往回跑一个点再去

using namespace std;
const int MAXV = 5005;


struct edge
{
	int to;
	int cost;
	edge(int _to, int _d) :to(_to), cost(_d) {};
};

int d1[MAXV], d2[MAXV];

vector<edge> g[MAXV];//第i个点的相连边
//vector<edge> E[MAXV];//所有单向边
vector<edge>::iterator it;

const int INF = INT_MAX;
queue<int> q;
bool inq[MAXV];//是否在队列中


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
	fill(inq + 1, inq + 1 + n, false);

	q.push(1);

	while (q.size()) {
		int i = q.front(); q.pop();
		inq[i] = false;
		for (it = g[i].begin(); it != g[i].end(); it++) {
			edge e = *it;
			int j = e.to;
			if (d1[i] + e.cost < d1[j]) {
				d1[j] = d1[i] + e.cost;
				if (!inq[j]) {
					q.push(j);
					inq[j] = true;
				}
			}
		}
	}

	fill(inq + 1, inq + 1 + n, false);
	fill(d2 + 1, d2 + 1 + n, INF);
	d2[n] = 0;
	q.push(n);

	while (q.size()) {
		int i = q.front(); q.pop();
		inq[i] = false;
		for (it = g[i].begin(); it != g[i].end(); it++) {
			edge e = *it;
			int j = e.to;
			if (d2[i] + e.cost < d2[j]) {
				d2[j] = d2[i] + e.cost;
				if (!inq[j]) {
					q.push(j);
					inq[j] = true;
				}
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
			if (d1[u] + e.cost + d2[v]<min2d && d1[u] + e.cost + d2[v]>mind)
				min2d = d1[u] + e.cost + d2[v];
		}
	}
	if (min2d == INF) {
		//只有最短路没有次短路，强行构造次短路
		//加上终点相连边距离的2倍
		min2d = mind + 2 * g[n][0].cost;
	}
	cout << min2d << endl;
	return 0;
}