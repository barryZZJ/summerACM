#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

//m条路是双向边，权重为正，w个虫洞是单向边，权重为负
//spfa求最短距离，如果有负环就能回到过去，否则不能。
const int MAXV = 505;
struct edge
{
	int to, cost;
	edge(int _to, int _d) :to(_to), cost(_d) {};
};
vector<edge> g[MAXV];//第i个点的相连边
vector<edge>::iterator it;
int d[MAXV];
const int INF = 999999999;
queue<int> q;
bool inq[MAXV];//是否在队列中
int show[MAXV];//点i出现的次数，超过n有负环

void addEdge(const int &f, const int &t, const int &cost) {
	g[f].push_back(edge(t, cost));
}

//判断负环的spfa
bool negative_spfa(int v, int start) {
	d[start] = 0;
	q.push(start);

	while (q.size()) {
		int i = q.front(); q.pop();
		inq[i] = false;
		for (it = g[i].begin(); it != g[i].end();it++) {
			edge e = *it;
			int j = e.to;
			if (d[i] + e.cost < d[j]) {
				d[j] = d[i] + e.cost;
				if (!inq[j]) {
					q.push(j);
					inq[j] = true;
					show[j]++;
					if (show[j] > v)
						return true;//入队超过n次，有负环
				}
			}
		}
	}
	return false;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		int v, m, w;
		cin >> v >> m >> w;
		
		fill(d + 1, d + v + 1, INF);
		fill(inq + 1, inq + 1 + v, false);
		fill(show + 1, show + 1 + v, 0);
		
		for (int i = 0;i < m;i++) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			addEdge(u, v, c);
			addEdge(v, u, c);
		}
		for (int i = 0;i < w;i++) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			addEdge(u, v, -c);

		}
		d[1] = 0;
		if (negative_spfa(v, 1)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		//记得初始化g[]
		for (int i = 1; i <= v; i++) {
			g[i].clear();
		}

	}

	return 0;
}
