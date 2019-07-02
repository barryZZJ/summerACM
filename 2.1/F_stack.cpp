//利用栈构造整数序列

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> resq;
bool ans[99999999];

int s[5][5];
int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };

void cls(stack<int> &q) {
	while (q.size()) q.pop();
}

int index(stack<int> q) {
	int tmp=1;
	while (q.size()) {
		tmp = tmp * 10 + q.top();
		q.pop();
	}
	return tmp;
}

int res=0;
void dfs(int x, int y, int t) {

	resq.push(s[x][y]);
	//cout << "step " << t << endl;
	//for (int i = 0;i < 5;i++) {
	//	for (int j = 0;j < 5;j++) {
	//		if (i == x && j == y) cout << "x ";
	//		else cout << s[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << index(resq) % 1000000 << endl;
	//cout << endl;
	
	if (t == 6) {
		int tmp = index(resq);
		if (ans[tmp] == false) {
			ans[tmp] = true;
			//cout << tmp % 1000000 << endl;
			res++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (0 <= x + dx[i] && x + dx[i] < 5 && 0 <= y + dy[i] && y + dy[i] < 5) {

			dfs(x + dx[i], y + dy[i], t + 1);
			resq.pop();

		}
	}


}

int main() {

	for (int i = 0;i < 5;i++)
		for (int j = 0;j < 5;j++)
			scanf("%d", &s[i][j]);

	for (int i = 0;i < 5;i++)
		for (int j = 0;j < 5;j++) {
			dfs(i, j, 1);
			resq.pop();
		}
		
	cout <<res<<endl;
	

	return 0;
}
