#include <bits/stdc++.h> 
using namespace std;
int n, m, ans, ac[1005], pos;
int Rand(int n){
	return rand()%(n+1); 
}
int Rand(int l, int r){
	return l + rand()%(r-l+1);
}
int main()
{
	//freopen("in.txt", "w", stdout);
	srand(time(0));
	int n = Rand(2,5);
	int m = Rand(2,5);
	cout<<m<<" "<<n<<endl;
	int map[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			map[i][j] = Rand(1);
	int sx = Rand(n), sy = Rand(m);
	map[sx][sy] = 2;
	int gx = Rand(n), gy = Rand(m);
	while(sx==gx && sy==gy){
		gx = Rand(n); gy = Rand(m);
	}
	map[gx][gy] = 3;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}
	cout<<"0 0";

	return 0;
 } 