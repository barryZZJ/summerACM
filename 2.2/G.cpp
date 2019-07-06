#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

//m' = 2*sqrt(m1*m2)
//求不停地碰撞后最小总重，小数点后3位
//最重的和次重撞，数越大开方缩小的程度越明显
const int MAXN = 105;
double w[MAXN];//每只重量

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) scanf("%lf", &w[i]);
	sort(w + 1, w + 1 + n);
	
	
	for (int i = n-1;i >= 1;i--) {
		w[i] = 2.0 * sqrt(w[i] * w[i+1]);
	}
	printf("%.3f\n", w[1]);//有坑，用.3lf就不过

	return 0;
}