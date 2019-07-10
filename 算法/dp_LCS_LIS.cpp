#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

//最长公共子序列
void LCS(int dp, int lena, int lenb){
	//dp初始化为0
	for(i=1;i<=lena;i++){
		for(j=1;j<=lenb;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d\n",dp[lena][lenb]);
}

//最长上升子序列
void LIS(){
	int low[MAXN] = INF;
	int a[MAXN], n;
	//边缘条件
	low[1] = a[i];
	int len=1;

	for (int i = 2; i <= n; i++){
		if(a[i]>low[len]) low[++len]=a[i];
		else{
			//找到第一个大于a[i]的位置，更新成a[i]
			int m = lower_bound(low+1,low+1+n,a[i]) - low;
			low[m] = a[i];
		}
	}
	cout<<len;
}

int main() {
	

	return 0;
}