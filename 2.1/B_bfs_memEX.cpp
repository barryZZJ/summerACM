//冰壶
//1.只走直线，撞墙停止（不能对着相邻墙），墙消失
//2.出界结束
//3.到达终点获胜
//4.至多走10次，否则输

//求，是否能到达终点，不能的话-1，能的话求最少步数

//0 0结束输入， 数据不超过100

//bfs，一条线的终点为下一个位置，棋盘对应更新，判断四个方向能不能到达（有墙挡着，不挨着墙，或有终点，或超出10步）

#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;


enum direct {
	up, dn, lt, rt
};

struct point
{
	int x;
	int y;
	int s[21][21];
	int step;

	point(int _x, int _y) :x(_x), y(_y) {};
	point(const point &p2) { x = p2.x; y = p2.y;
		if (0 <= p2.s[0][0] && p2.s[0][0] <= 3) {
			step = p2.step;
			for (int i = 0;i < 21;i++)
				for (int j = 0; j < 21;j++)
					s[i][j] = p2.s[i][j];
		}
	}
	bool operator ==(const point p2) {
		if (this->x == p2.x && this->y == p2.y) return true;
		return false;
	}
	point operator =(const point &p2) {
		this->x = p2.x;
		this->y = p2.y;
		if (0 <= p2.s[0][0] && p2.s[0][0] <= 3) {
			this->step = p2.step;
			for (int i = 0;i < 21;i++)
				for (int j = 0; j < 21;j++)
					this->s[i][j] = p2.s[i][j];
		}
		return *this;
	}
};


int ans;
const point nullp(-1, -1);
const point gp(-2, -2);
int n, m;
queue<point> q;

point move(point &p, direct d) {
	//return target point or nullp 到不了， 
	point np = p;
	switch (d)
	{
	case up:
		if (np.s[np.x - 1][np.y] == 1) return nullp;
		while (np.s[--np.x][np.y] != 1) {

			if (np.s[np.x][np.y] == 3){ //终点
				point p = gp;
				p.step = np.step;
				return p;
			}
			if (np.x < 0 || np.x >= n || np.y < 0 || np.y >= m) //出界
				return nullp;
		}
		//到了
		np.x++;
		np.s[np.x - 1][np.y] = 0;
		return np;
		break;

	case dn:

		if (np.s[np.x + 1][np.y] == 1) return nullp;
		while (np.s[++np.x][np.y] != 1) {

			if (np.s[np.x][np.y] == 3){ //终点
				point p = gp;
				p.step = np.step;
				return p;
			}
			if (np.x < 0 || np.x >= n || np.y < 0 || np.y >= m) //出界
				return nullp;
		}
		//到了
		np.x--;
		np.s[np.x + 1][np.y] = 0;
		return np;
		break;
	case lt:
		if (np.s[np.x][np.y - 1] == 1) return nullp;
		while (np.s[np.x][--np.y] != 1) {

			if (np.s[np.x][np.y] == 3){ //终点
				point p = gp;
				p.step = np.step;
				return p;
			}
			if (np.x < 0 || np.x >= n || np.y < 0 || np.y >= m) //出界
				return nullp;
		}
		//到了
		np.y++;
		np.s[np.x][np.y - 1] = 0;
		return np;
		break;
	case rt:
		if (np.s[np.x][np.y + 1] == 1) return nullp;
		while (np.s[np.x][++np.y] != 1) {

			if (np.s[np.x][np.y] == 3) { //终点
				point p = gp;
				p.step = np.step;
				return p;
			}
			if (np.x < 0 || np.x >= n || np.y < 0 || np.y >= m) //出界
				return nullp;
		}
		//到了
		np.y--;
		np.s[np.x][np.y + 1] = 0;
		return np;
		break;
	}
}

direct directs[4] = { lt,rt,up,dn };
bool seen[21][21];

bool bfs() {

	while (q.size()) {
		point p = q.front(); q.pop();

		if (p.step >= 10) continue; 

		for (int i = 0; i < 4; i++) {
			point np = move(p, directs[i]);
			if (np == nullp || seen[np.x][np.y]) continue;

			np.step++;
			//for (int i = 0;i < n;i++) {
			//	for (int j = 0; j < m;j++) {
			//		//np.s[i][j] = p.s[i][j];
			//		if (point(i, j) == point(np.x, np.y))
			//			cout << "x ";
			//		else
			//			cout << np.s[i][j] << " ";
			//	}
			//	cout << endl;
			//}
			//cout << endl;

			if (np == gp) {
				ans = np.step;
				return true;
			}

			seen[np.x][np.y] = true;
			

			q.push(np);

		}

	}
	return false;

}

point sp = nullp;

int main() {
	//m*n = w*h
	int s[21][21];
	while (~scanf("%d%d", &m, &n)) {
		if (m == 0 && n == 0) break;
		ans = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m; j++) {
				scanf("%d", &s[i][j]);
				seen[i][j] = false;
				if (s[i][j] == 2) {
					sp = point(i, j);
					s[i][j] = 0;
				}
			}
		}
		//cout << endl;

		for (int i = 0;i < n;i++)
			for (int j = 0; j < m;j++)
				sp.s[i][j] = s[i][j];
		sp.step = 0;

		q.push(sp);

		if (bfs())
			cout << ans << endl;
		else
			cout << -1 << endl;
		while (q.size()) {
			q.pop();
		}

	}


	return 0;
}