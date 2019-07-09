#include <iostream>
#include <algorithm>

using namespace std;

//完全背包就是01背包剩余容量改成正序遍历
const int MAXN = 105;
int d[MAXN];//滚动数组
int W, v[MAXN], w[MAXN], n;

//滚动数组
void completeBagDP(){
	for(int i=1; i<=n; i++){
		for(int j=w[i]; j<=W; j++){//j小于w[i]放不下，一定不更新
			d[j] = max(d[j], d[j-w[i]] + v[i]);
			// if(d[j-w[i]] + v[i] > d[j])
			// 	d[j] = d[j-w[i]] + v[i];
		}
	}
	cout<<d[W];
}

int main(){
	

	return 0;
}