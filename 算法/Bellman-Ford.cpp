//主要找单向边
//从起点到第i个点的最短距离di = min{d(j) + w(i,j) | j与i相邻}
// (所有（到点i相邻的点（j）的最小距离 + 这两个点的距离）中的最小值）
//实现方法：存边的to, distance，初始化最短路径数组d[]为INF，，d[起点]=0。
//按点遍历，每个点遍历一次所有的相连边。 d(i) 就是mint(d[e.to] + e.distance)
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

struct edge
{
	int to, cost;
	edge(int _to, int _d) :to(_to), cost(_d) {};
};

const int MAXV = 100;//点数
vector<edge> g[MAXV];//第i个点的相连边
vector<edge>::iterator it;
int d[MAXV];
const int INF = INT_MAX;

//不判断负环的Bellman，不用
void BellmanFord(int v) {
	//s 起点
	bool update;
	do {
		update = false;
		for (int j = 1;j <= v;j++) {
			for (it = g[j].begin(); it != g[j].end(); it++) {
				edge e = *it;
				int i = e.to;
				if (d[j] != INF && d[j] + e.cost < d[i]) {
					d[i] = d[j] + e.cost;
					update = true;
				}
			}
		}
		
	} while (update);

}

//存在负圈则会经过同一个点两次
//没有负圈的话遍历完v-1个点d[v]就应该有了，如果走到v再走点v到点v的邻边比直接到v的邻边还短（会更新d[邻边]）
//说明存在负环

//存在负圈返回true
bool negative_BellmanFord(int v, int start) {
	//如果d[start]为负则存在负环
	bool update;
	do {
		update = false;
		for (int j = 1; j <= v; j++) {
			for (it = g[j].begin(); it != g[j].end(); it++) {
				edge e = *it;
				int i = e.to;
				if (d[j] != INF && d[j] + e.cost < d[i]) {
					d[i] = d[j] + e.cost;
					update = true;
				}
			}
		}
		if (d[start] < 0) return true;//存在负环
	} while (update);
	return false;
}

void addEdge(const int &f, const int &t, const int &cost) {
	g[f].push_back(edge(t, cost));
}

int main() {
	////输入数据
	//无负环
	//int v = 6;
	//
	//g[1].push_back(edge(2, 5));	g[1].push_back(edge(3, 1));
	//g[2].push_back(edge(1, 5));	g[2].push_back(edge(3, 2));	g[2].push_back(edge(4, 1));
	//g[3].push_back(edge(1, 1));	g[3].push_back(edge(2, 2));	g[3].push_back(edge(4, 4));	g[3].push_back(edge(5, 8));
	//g[4].push_back(edge(2, 1));	g[4].push_back(edge(3, 4));	g[4].push_back(edge(5, 3));	g[4].push_back(edge(6, 6));
	//g[5].push_back(edge(3, 8));	g[5].push_back(edge(4, 3));
	//g[6].push_back(edge(4, 6));
	
	//有负环
	int v = 4;
	addEdge(1, 2, 1); //addEdge(1, 4, -3);
	addEdge(2, 3, 1); //addEdge(2, 1, 1);
	addEdge(3, 4, 1); //addEdge(3, 2, 1);
	addEdge(4, 1, -4); //addEdge(4, 3, 1);
	
	for (int start = 1; start <= v; start++) {
		//初始化
		fill(d + 1, d + 1 + v, INF);
		d[start] = 0;//起点

		if (negative_BellmanFord(v, start)) {
			cout << "negative found" << endl;
			return 0;
		}
		else {
			for (int i = 1; i <= v; i++) {
				cout << start << "->" << i << " : " << d[i] << endl;

			}
		}
	}


}

