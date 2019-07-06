//spfa：带队列的bellman，主要找单向边
//从起点到第j个点的最短距离d(j) = min{d(i) + w(j,i) | i与j相邻}
// (所有（到点i相邻的点（j）的最小距离 + 这两个点的距离）中的最小值）
//队列中有点x代表需要松弛x的邻接点j(需要更新d[j]就更新）；
//使用队列的话如果某个点i（别的点j和k的邻接点）spfa：更新d[j]、d[k]的时候i需要被更新就先记下来，而bellman：更新d[j]和d[k]的时候立刻松弛d[i]，就会多一些计算
//实现：
//存边的to, cost，初始化最短路径数组d[]为INF，d[起点]=0。起点push进队列
//队列中取出的点i代表要松弛i的邻接点
//从队列中依次取点i，遍历邻接点j(g[i][].to)，并对d[j]进行松弛操作（如果需要更新则满足(d[i] + e.cost) < d[j]）
//	（注意“更新”代表d[j]要变小了）
//如果更新了d[j] = d[i] + e.cost：
//	因为d[j]变了，与j相邻的点都要重新松弛，所以放入队列中代表j的相邻点待松弛。
//但如果队列中已经有j的相邻点（取出别的点的时候已经标记要更新这个点了）就不用入队了
//看j在不在队列中，不在的话就push(j)，在的话就跳过
//如果没更新j就再取点
//直到队空

//期间记录每个点入队的次数，如果超过n（总点数）次则有负环

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct edge
{
	int to, cost;
	edge(int _to, int _d) :to(_to), cost(_d) {};
};

const int MAXV = 1005;//点数
vector<edge> g[MAXV];//第i个点的相连边
vector<edge>::iterator it;
int d[MAXV];
const int INF = 999999999;//INT_MAX会爆
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

//不判断负环的spfa
void spfa(int start) {
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
	//初始化
	int v = 7;

	//参考图：http://keyblog.cn/uploads/20181007/1_1.png
	//参考结果（1为起点）d[1]=0, d[2]=17, d[3]=8, d[4]=15, d[5]=13, d[6]=11, d[7]=14
	addEdge(1, 2, 24);
	addEdge(1, 3, 8);
	addEdge(1, 4, 15);
	addEdge(2, 5, 6);
	addEdge(3, 5, 7);
	addEdge(3, 6, 3);
	addEdge(4, 7, 4);
	addEdge(5, 7, 9);
	addEdge(6, 4, 5);
	addEdge(6, 5, 2);
	addEdge(6, 7, 3);
	addEdge(7, 2, 3);

	////有负环
	//int v = 4;
	//addEdge(1, 2, 1); //addEdge(1, 4, -3);
	//addEdge(2, 3, 1); //addEdge(2, 1, 1);
	//addEdge(3, 4, 1); //addEdge(3, 2, 1);
	//addEdge(4, 1, -4); //addEdge(4, 3, 1);

	fill(inq + 1, inq + 1 + v, false);
	fill(d + 1, d + 1 + v, INF);
	fill(show + 1, show + 1 + v, 0);

	int start = 1;

	d[start] = 0;
	/*spfa(start);*/
	if (negative_spfa(v, start))
	{
		cout << "nagative found" << endl;
		return 0;
	}
	else {
		for (int i = 1; i <= v;i++) {
			cout << "1->" << i << " : " << d[i] << endl;
		}
	}
	
	return 0;
}