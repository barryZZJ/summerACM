//也可以不存d[]，存每一个点的父节点，求d的时候回溯
//点编号为数字， 用map存邻接矩阵
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 100;

map<int, map<int, int>> graph;
int d[MAXN];

struct cmp
{
	bool operator()(const int &s1, const int &s2) {
		return d[s1] > d[s2];
	}
};


bool seen[MAXN];
const int INF = 10000;

priority_queue<int, vector<int>, cmp> pq;

int main() {

	graph[1][2] = 5;
	graph[1][3] = 1;
	graph[2][1] = 5;
	graph[2][3] = 2;
	graph[2][4] = 1;
	graph[3][1] = 1;
	graph[3][2] = 2;
	graph[3][4] = 4;
	graph[3][5] = 8;
	graph[4][2] = 1;
	graph[4][3] = 4;
	graph[4][5] = 3;
	graph[4][6] = 6;
	graph[5][3] = 8;
	graph[5][4] = 3;
	graph[6][4] = 6;

	int start = 1;
	int n = 6;

	for(int i=1;i<=n;i++){
		if(i==start) d[i] = 0;
		else d[i] = INF;
	}

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
		cout << i << " : " << d[i] << endl;
	}

}
