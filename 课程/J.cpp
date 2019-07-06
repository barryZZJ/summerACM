//差分约束https://blog.csdn.net/zhouzejun1/article/details/94864280
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

//dv<=du + w(u,v)
//dv - du <= w(u,v)
//构造从u到v的一条边，权重为w(u,v)（注意不等号方向）
//结果为1到n的最短路径

//如果有负环就-2
struct edge
{
	int to, cost;
	edge(int _to, int _d) :to(_to), cost(_d) {};
};

const int MAXV = 1005;//点数
vector<edge> g[MAXV];//第i个点的相连边
vector<edge>::iterator it;
int d[MAXV];
const int INF = INT_MAX;
queue<int> q;
bool inq[MAXV];//是否在队列中
int show[MAXV];//点i出现的次数，超过n有负环

//判断负环的spfa
bool negative_spfa(int v, int start) {

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

void addEdge(const int &f, const int &t, const int &cost) {
	g[f].push_back(edge(t, cost));
}

int main() {
	int v,ml,md;
	cin>>v>>ml>>md;
	//ml:B-A<=D
	//md:A-B<=-D
	int a, b, cost;
	while(ml--){
		scanf("%d%d%d",a,b,cost);
		addEdge(a,b,cost);
	}
	while(md--){
		scanf("%d%d%d",a,b,cost);
		addEdge(b,a,-cost);
	}

	//初始化

	int ans;
	if(negative_spfa){
		ans = -2;
	}else{
		d[v]
	}

	return 0;
}