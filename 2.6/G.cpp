#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

//快速幂
//a^b = a^(1) * a^(2^1) * a^(2^2) * a^(2^3)....
//b的二进制数的第i位乘以第i项
ll qpow(ll a, ll b, ll mod) {
	ll re = 1;
	while (b) {
		if (b & 1) {
			re = (re*a) % mod;
		}
		b >>= 1;
		a = (a*a) % mod;
	}
	return re % mod;
}
int z, m, h;
ll a, b;
ll ans;
int main() {
	cin >> z;
	while (z--) {
		ans = 0;
		cin>> m >> h;
		ll tmp;
		for (int i = 1;i <= h;i++) {
			scanf("%lld%lld", &a, &b);
			tmp = qpow(a, b, m);
			ans += tmp;
		}
		printf("%lld\n", ans%m);
	}
	return 0;
}