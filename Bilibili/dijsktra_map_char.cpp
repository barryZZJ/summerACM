//也可以不存d[]，存每一个点的父节点，求d的时候回溯
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;


const int MAXN = 100;//总共点的个数

map<char, map<char, int>> graph;
map<char, int> d;

struct cmp
{
	bool operator()(const char &s1, const char &s2) {
		return d[s1] > d[s2];
	}
};

map<char, bool> seen;
const int INF = 10000;

priority_queue<char, vector<char>, cmp> pq;

int main() {

	graph['A']['B'] = 5;
	graph['A']['C'] = 1;
	graph['B']['A'] = 5;
	graph['B']['C'] = 2;
	graph['B']['D'] = 1;
	graph['C']['A'] = 1;
	graph['C']['B'] = 2;
	graph['C']['D'] = 4;
	graph['C']['E'] = 8;
	graph['D']['B'] = 1;
	graph['D']['C'] = 4;
	graph['D']['E'] = 3;
	graph['D']['F'] = 6;
	graph['E']['C'] = 8;
	graph['E']['D'] = 3;
	graph['F']['D'] = 6;
	d['A'] = 0;
	d['B'] = INF;
	d['C'] = INF;
	d['D'] = INF;
	d['E'] = INF;
	d['F'] = INF;

	int n = 6;
	fill(seen + 1, seen + n + 1, false);

	pq.push('A');
	while (pq.size()) {
		char tn = pq.top(); pq.pop();
		seen[tn] = true;
		for (map<char, int>::iterator it = graph[tn].begin(); it != graph[tn].end(); it++) {
			//it为邻接点
			char adj = it->first; //邻接点编号
			int distance = it->second;
			if (!seen[adj]) {
				d[adj] = min(d[adj], d[tn] + distance);
				pq.push(adj);
			}

		}
	}
	for (map<char, int>::iterator it = d.begin(); it != d.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}

}
