#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
const int MAXN = 1000005;
//解题思路：
//可以将n用二进制表示.
//i为奇数时,d[i] = d[i-1]
//i为偶数时，n的分解结果分两种情况 
//1.含有1, n=n-2+1+1, 这种情况可以直接在n-1的分解结果中添加一个1即可，为d[n-1] = d[n-2]
//2.不含有1, n=2/2*2, 那么，分解因子的都是偶数，将每个分解的因子都除以2，刚好是n / 2的分解结果，并且可以与之一一对应，这种情况有 s[n / 2]

int n;
int d[MAXN];


int main() {
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= MAXN;i++) {
		if (i % 2 == 1) d[i] = d[i - 1] % 1000000000;
		else d[i] = (d[i - 2] + d[i / 2]) % 1000000000;
	}

	while(cin >> n)	cout << d[n]<<endl;


	return 0;
}