#include <iostream>
#include <stdio.h>
using namespace std;

int n=5 ;
int a[]={2,1,9,5,7};
int k=13;
int cnt=1;

char b[4];


bool dfs(int pos,int sum){
	cout<<cnt++<<endl;
	// if(sum>k) return false;
	if(pos==n) return sum==k;

	// b[pos] = a[pos]+48;
	// cout<<"trying"<<b<<endl;
	if(dfs(pos+1,sum+a[pos])) return true;
	if(dfs(pos+1,sum)) return true;
	// cout<<"no good"<<endl;
	
	// b[pos] = 32;
	// cout<<"trying"<<b<<endl;
	// cout<<"no good"<<endl;
	return false;
}

int main(){
	cout<<dfs(0,0);
	return 0;
}