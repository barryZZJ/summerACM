//构造字典序最小的字符串
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
	char a[2005];
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%s", &a[i]);
	}
	int is = 0;
	int l = 0, r = n - 1;
	//从两头找，直到不相同，取更小的那个方向
	int i = 0;
	while (l <= r) {
		bool ls = false;//left_start
		for (int ofset = 0; l + ofset < r - ofset; ofset++) {
			if (a[l + ofset] == a[r - ofset]) continue;
			if (a[l + ofset] > a[r - ofset]) {
				ls = false;
				break;
			}else{
				ls = true;
				break;
			}

		}
		if (i != 0 && i % 80 == 0) putchar('\n');
		if (ls) putchar(a[l++]);
		else putchar(a[r--]);
		i++;
	}

	return 0;
}