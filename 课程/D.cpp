#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int r, n;
int x[1005];
int ans;
void index(int l) {
	int mid = l;
	bool flag = false;
	for (int i = l;i < n-1;i++) {
		if (!flag && (x[i+1] - x[l]) > r) {
			ans++;
			mid = i;
			flag = true;
		}
		if (flag && (x[i+1] - x[mid]) > r) {
			index(i+1);
			return;
		}

	}
	if(!flag) ans++;//这里忘加判断条件了，！flag说明没有插过旗，此时这一组数据才应点灯
}

int main() {
	while (scanf("%d%d", &r, &n) == 2) {
		ans = 0;
		if (r == -1 && n == -1) break;
		for (int i = 0;i < n;i++)
			scanf("%d", &x[i]);
		sort(x, x + n);
		index(0);
		cout << ans<<endl;
	}

	return 0;
}