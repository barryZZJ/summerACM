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

int ans =0 ;

void dfs(point p){

	ans++;
	tiles[p.x][p.y] = '#';

	for(int i=0; i<4; i++){
		point np(p.x + directs[i].x, p.y + directs[i].y);
		if (0 <= np.x && np.x < n && 0 <= np.y && np.y < m && tiles[np.x][np.y] == '.') {
			dfs(np);
		}
	}

}


int main() {
	while (~scanf("%d%d", &m, &n)) { //w = m col; h=n row

		if(m==0 && n==0) break;

		for (int i = 0; i < n; i++) {
			scanf("%s", &tiles[i]);
			for (int j = 0; j < m; j++) {
				if (tiles[i][j] == '@') {
					sp = point(i, j);
					break;
				}
			}
		}
		
		dfs(sp);
		cout << ans << endl;
		ans=0;
	}


	return 0;
}