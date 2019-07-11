#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;


bool isPrime(ll a) {
	if (a == 2) return true;
	for (ll i = 2; i <= sqrt(a) + 1; i++) {
		if (a%i == 0) return false;
	}
	return true;
}

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
ll p, a;
ll ans;
int main() {
	while (scanf("%lld%lld", &p, &a) == 2) {
		if (!p && !a) break;
		if (!isPrime(p) && qpow(a, p, p) == a%p) 
			printf("yes\n");
		else 
			printf("no\n");
	}
	
	return 0;
}