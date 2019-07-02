//直接构造整数序列

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool ans[99999999];

int s[5][5];
int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };


int res=0;

void dfs(int x, int y, int t, int index) {

	//cout << "step " << t << endl;
	//for (int i = 0;i < 5;i++) {
	//	for (int j = 0;j < 5;j++) {
	//		if (i == x && j == y) cout << "x ";
	//		else cout << s[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	int thisi = index*10 + s[x][y];
	if (t == 6) {
		if (ans[thisi] == false) {
			ans[thisi] = true;
			//cout << tmp % 1000000 << endl;
			res++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (0 <= x + dx[i] && x + dx[i] < 5 && 0 <= y + dy[i] && y + dy[i] < 5) {

			dfs(x + dx[i], y + dy[i], t + 1,thisi);

		}
	}


}

int main() {

	for (int i = 0;i < 5;i++)
		for (int j = 0;j < 5;j++)
			scanf("%d", &s[i][j]);

	for (int i = 0;i < 5;i++)
		for (int j = 0;j < 5;j++) {
			dfs(i, j, 1,1);
		}
		
	cout <<res<<endl;
	

	return 0;
}
