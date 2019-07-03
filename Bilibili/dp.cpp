//注意数组第0项，第0个工作
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

const int MAXN=8+1;
int v[]={0,5,1,8,4,6,3,2,4};
int pre[]={-1,0,0,0,1,0,2,3,5};
int opt[MAXN];

int dp(int i){
	if (opt[i]>=0) return opt[i];
	int res;
	if(i==0) res = 0;
	else res = max(dp(i-1), dp(pre[i])+v[i]);
	return opt[i] = res;
}

int main(){
	memset(opt, -1, sizeof(opt));
	cout<<dp(8);
}
