#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
//按t/d升序排序
// 二头牛 A,B,属性分别为分别为eatA,timeA,eatB,timeB
// 选A的时候损失的花为 timeA*eatB
// 选B的时候损失的花为 timeB*eatA
// 贪当前损失的花最少的，两边同除timeA*timeB，得到eB/tB 和 eA/tA
// 令eat/time为羊的比率
// 应该先送走“吃花率”强的

typedef long long ll;
const int MAXN = 100005;

struct P
{
	int t, d;
}p[MAXN];

bool cmp(P p1, P p2){
	return p1.d*1.0/p1.t > p2.d*1.0/p2.t;
}
ll ans=0;
int main() {
	int n;
	cin>>n;
	int sd=0;
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&p[i].t,&p[i].d);
		sd+=p[i].d;
	}
	sort(p+1, p+1+n, cmp);
	for(int i=1; i<=n; i++){
		sd-=p[i].d;
		ans+=sd*p[i].t*2;
	}
	cout<<ans<<endl;
	return 0;
}