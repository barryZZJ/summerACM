#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct point
{
	int x;
	int y;
	point(int _x, int _y) :x(_x), y(_y) {};
};

int n, m;
int s[21][21];
point d[4] = { point(0,1),point(0,-1),point(1,0),point(-1,0) };
int ans;

void show(point np, int step) {

	cout << step << endl;
	for (int i = 0;i < n;i++) {
		for (int j = 0; j < m;j++) {
			if (i == np.x && j== np.y)
				cout << "x ";
			else
				cout << s[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void dfs(point p, int step) {

	if (step >= 10 || step >= ans) return;
	if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) return;

	for (int i = 0; i < 4; i++) {

		point tp(p.x + d[i].x, p.y + d[i].y);
		bool flag = false;

		if (tp.x < 0 || tp.x >= n || tp.y < 0 || tp.y >= m)
			continue;

		if (s[tp.x][tp.y] == 1)
			continue;

		while (s[tp.x][tp.y] != 1) {

			if (tp.x < 0 || tp.x >= n || tp.y < 0 || tp.y >= m) { //出界
				flag = true;
				break;
			}

			if (s[tp.x][tp.y] == 3) { //终点
				ans = min(ans, step + 1);
				//show(tp, step + 1);
				//system("pause");
				flag = true;
				break;
			}

			tp.x += d[i].x; tp.y += d[i].y;

            if (tp.x < 0 || tp.x >= n || tp.y < 0 || tp.y >= m) { //出界
				flag = true;
				break;
			}
		}
		if (!flag) {
			//到了

			tp.x -= d[i].x; tp.y -= d[i].y;

			s[tp.x + d[i].x][tp.y + d[i].y] = 0;

			//show(tp, step + 1);

			dfs(tp, step + 1);

			s[tp.x + d[i].x][tp.y + d[i].y] = 1;

			continue;

		}
	}
}

int main() {
	while (~scanf("%d%d", &m, &n)) {
		ans = 99999999;
		memset(s, 0, sizeof(s));
		if (m == 0 && n == 0) break;
		point sp(-1, -1);
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m; j++) {
				scanf("%d", &s[i][j]);
				if (s[i][j] == 2) {
					sp = point(i, j);
					s[i][j] = 0;
				}
			}

		}
		dfs(sp, 0);
		if (ans != 99999999)
			cout << ans << endl;
		else
			puts("-1");
	}


	return 0;
}



