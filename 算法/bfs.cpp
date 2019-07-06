#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct point
{
	int x;
	int y;
	point(int _x,int _y):x(_x),y(_y){};
};

const int n=10,m=10;
const int INF=1e8;
int d[n][m];

point sp(0,1), gp(9,8);
point directs[4] = {point(1,0),point(-1,0),point(0,1),point(0,-1)};

char maze[n][m+1]={
	"#S######.#",
	"......#..#",
	".#.##.##.#",
	".#........",
	"##.##.####",
	"....#....#",
	".#######.#",
	"....#.....",
	".####.###.",
	"....#...G#"
};

int bfs(){
	queue<point> q;
	q.push(sp);
	d[sp.x][sp.y] = 0;
	while(!q.empty()){
		point p = q.front();
		q.pop();
		if (p.x == gp.x && p.y == gp.y) break;

		for(int i=0;i<4; i++){
			point np(p.x+directs[i].x, p.y+directs[i].y);

			if(0<= np.x && np.x< n && 0<= np.y && np.y<m && maze[np.x][np.y]!='#' && d[np.x][np.y] == INF){
				q.push(np);
				d[np.x][np.y] = d[p.x][p.y]+1;
			}
		}
	}
	return d[gp.x][gp.y];

}

int main() {
	
	for(int i=0; i<n; i++)
		for(int j=0;j<m;j++)
			d[i][j] = INF;

	
	cout<<bfs();
	return 0;
}