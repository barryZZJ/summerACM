#include <iostream>

using namespace std;

typedef long long ll;

//a^b = a^(1) * a^(2^1) * a^(2^2) * a^(2^3)....
//b的二进制数的第i位乘以第i项
ll qpow(ll a, ll b, ll mod){
	ll re = 1;
	while(b){
		if(b & 1){
			re= (re*a)%mod;
		}
		b>>=1;
		a = (a*a)%mod;
	}
	return re%mod;
}

int main(){

	return 0;
}