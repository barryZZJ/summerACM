#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

struct point {
	int x;
	int y;
	point(int _x, int _y) :x(_x), y(_y) {};
};

int m, n;
char tiles[21][21];
point sp(0, 0);
point directs[4] = { point(1,0),point(0,-1),point(-1,0),point(0,1) };
queue<point> q;


int bfs() {

	int ans=0;
	while (q.size()) {

		point tp = q.front();q.pop();

		for (int i = 0; i < 4; i++) {
			point np(tp.x + directs[i].x, tp.y + directs[i].y);
			if (0 <= np.x && np.x < n && 0 <= np.y && np.y < m && tiles[np.x][np.y] == '.') {
				q.push(np);
				tiles[np.x][np.y] = '#';

				ans++;
			}
		}

	}
	return ans+1;
}


int main() {
	while (~scanf("%d%d", &m, &n)) { //w = m col; h=n row
		if(m==0 && n==0) break;
		for (int i = 0; i < n; i++) {
			scanf("%s", &tiles[i]);
			for (int j = 0; j < m; j++) {
				if (tiles[i][j] == '@') {
					sp = point(i, j);
					q.push(sp);
					break;
				}
			}
		}
		
		int ans = bfs();
		cout << ans << endl;

	}


	return 0;
}