#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int l,n;
		scanf("%d%d",&l,&n);
		int d[n];
		int minans=0,maxans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&d[i]);
			minans = max(min(d[i],l-d[i]),minans);
			maxans = max(max(d[i],l-d[i]),maxans);
		}
		cout<<minans<<" "<<maxans<<endl;
	}

	return 0;
}