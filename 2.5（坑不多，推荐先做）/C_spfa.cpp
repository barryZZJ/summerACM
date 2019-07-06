//Floyd爆时间，改用两次spfa
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
//单向边
//起点i，终点x
//求max(d[i][x] + d[x][i])
//求两次spfa（第二次把单向边反向再对x求）

struct edge
{
	int to, cost;
	edge(int _to, int _d) :to(_to), cost(_d) {};
};

const int INF = 999999999;
const int MAXV = 1005;
int d1[MAXV], d2[MAXV];
vector<edge> g1[MAXV];//第i个点的相连边
vector<edge> g2[MAXV];//第i个点的相连边
vector<edge>::iterator it;
queue<int> q;
bool inq[MAXV];//是否在队列中

void addEdge(vector<edge> (&g)[MAXV],const int &f, const int &t, const int &cost) {
	g[f].push_back(edge(t, cost));
}

//不判断负环的spfa
void spfa(int start, int(&d)[MAXV], vector<edge>(&g)[MAXV] ) {
	d[start] = 0;
	q.push(start);

	while (q.size()) {
		int i = q.front(); q.pop();
		inq[i] = false;
		for (it = g[i].begin(); it != g[i].end(); it++) {
			edge e = *it;
			int j = e.to;
			if (d[i] + e.cost < d[j]) {
				d[j] = d[i] + e.cost;
				if (!inq[j]) {
					q.push(j);
					inq[j] = true;
				}
			}
		}
	}
}

int main() {
	int v, m, x;
	cin >> v >> m >> x;
	
	fill(d1 + 1, d1 + 1 + v, INF);
	fill(d2 + 1, d2 + 1 + v, INF);

	for (int e = 0; e < m;e++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		addEdge(g1, u, v, c);
		addEdge(g2, v, u, c);

	}
	fill(inq + 1, inq + 1 + v, false);
	spfa(x, d1,g1);

	fill(inq + 1, inq + 1 + v, false);
	spfa(x, d2,g2);


	int ans = d1[1] + d2[1];
	for (int k = 2;k <= v;k++) {
		ans = max(ans, d1[k] + d2[k]);
	}
	cout << ans;

	return 0;
}