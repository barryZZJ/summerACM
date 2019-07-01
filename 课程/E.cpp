#include <iostream>
#include <stdio.h>
using namespace std;

//贪心，优先取最短的两个板子拼起来
//注意ans long long，爆int

int main(){
	int n;
	cin>>n;
	int l[n];
	for(int i=0;i<n;i++){
		scanf("%d",&l[i]);
	}
	long long ans=0;
	while(n>1){

		int mini=0, min2i=1;
		for(int i=1;i<n;i++){
			if(l[i]<l[mini]){
				min2i = mini;
				mini = i;
			}else if(l[i]<l[min2i]){
				min2i = i;
			}
			
		}
		int sum = l[mini]+l[min2i];
		
		ans += sum;
		if(mini != n-1){
			l[mini] = sum;
			l[min2i] = l[n-1];
		}
		else
			l[min2i] = sum;
		n--;

	}
	cout<<ans;

	return 0;
}