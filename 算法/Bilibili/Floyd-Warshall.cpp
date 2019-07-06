#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXV = 6;
const int INF = 99999999;//注意嗷不能用INT_MAX否则d[i][k] + d[k][j]一个INF加另一个数就变成了负数。。
int d[MAXV + 1][MAXV + 1];


int main() {
	for (int i = 1; i <= MAXV; i++) {
		for (int j = 1; j <= MAXV; j++) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}
	d[1][2] = 5; d[1][3] = 1;
	d[2][1] = 5; d[2][3] = 2; d[2][4] = 1;
	d[3][1] = 1; d[3][2] = 2; d[3][4] = 4; d[3][5] = 8;
	d[4][2] = 1; d[4][3] = 4; d[4][5] = 3; d[4][6] = 6;
	d[5][3] = 8; d[5][4] = 3;
	d[6][4] = 6;
	
	for (int k = 1;k <= MAXV; k++) 
		for (int i = 1; i <= MAXV; i++) 
			for (int j = 1; j <= MAXV; j++) 
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			
	for (int i = 1; i <= MAXV; i++) {
		for (int j = i; j <= MAXV; j++) {
			printf("%d->%d : ", i, j);
			cout<< d[i][j] << endl;
		}
	}



	return 0;
}