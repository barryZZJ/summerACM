#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;
int x[50005], y[50005], t[50005];

int mp[350][350];
int seen[350][350];
//当前没被毁：可以走，将来也不会被毁：是结果
//把被毁的地方设成被毁的时间，如果当前时间小于这个数就可以走
//mp[][] == -1:安全

int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };
struct P {
	int x; int y;
	int time;
};

queue<P> q;
// priority_queue<P> q;

int bfs() {
	while (q.size()) {
		P p = q.front(); q.pop();
		if (mp[p.x][p.y] == -1) return p.time;
		for (int i = 0;i < 4;i++) {
			int tx = p.x + dx[i], ty = p.y + dy[i];
			P tp; tp.x = tx; tp.y = ty; tp.time = p.time + 1;
			if (tx >= 0 && ty >= 0 && (mp[tx][ty] == -1 || tp.time < mp[tx][ty])) {
				if(!seen[tx][ty]){
					q.push(tp);
					
				}
				seen[tx][ty] = 1;//可以走的地方做标记，防止重复
			}
		}
	}
	return -1;
}

int main() {
	int m;
	scanf("%d",&m);
	for (int i = 1;i <= m;i++)
		scanf("%d%d%d", &x[i], &y[i], &t[i]);

	memset(mp, -1, sizeof(mp));
	memset(seen,0,sizeof(seen));
	//init map
	for (int i = 1;i <= m;i++) {
		if(mp[x[i]][y[i]] == -1)
			mp[x[i]][y[i]] = t[i];
		else
			mp[x[i]][y[i]] = min(t[i],mp[x[i]][y[i]]); //这里忘了
		
		for (int j = 0;j < 4;j++) {
			int tx = x[i] + dx[j], ty = y[i] + dy[j];
			if (tx >= 0 && ty >= 0) {
				if (mp[tx][ty] == -1)
					mp[tx][ty] = t[i];
				else
					mp[tx][ty] = min(t[i], mp[tx][ty]);
			}

		}
	}
	P sp;
	sp.x = 0; sp.y = 0; sp.time = 0;
	seen[0][0] = 1;
	q.push(sp);
	// for (int i = 0;i < 11;i++) {
	// 	for (int j = 0;j < 11;j++) {
	// 		if (mp[i][j] == -1)cout << "x";
	// 		else cout << mp[i][j];
	// 		cout << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	cout << bfs();
	
	return 0;
}