#include <iostream>
#include <stdio.h>
using namespace std;

char s[105][105];
int n,m;

void dfs(int x, int y) {
	s[x][y] = '.';
	int nx, ny;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			nx = x + dx; ny = y + dy;
			if (0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] == 'W')
				dfs(nx, ny);
		}
	}
}


int main() {
	
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", &s[i]);
	}

	int ans = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if(s[x][y] == 'W'){
			 	
			 	dfs(x,y);
			 	ans++;
			}
		}
	}
	cout << ans;

	return 0;
}