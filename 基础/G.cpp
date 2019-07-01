#include <iostream>

using namespace std;

int main(){
	int n;
	int m[6]={100,50,10,5,2,1};
	int money;
	
	while(scanf("%d",&n)!=EOF){
		int ans=0;
		if (n==0)break;
		for(int i=0; i<n;i++){
			scanf("%d",&money);
			for(int j=0; j<6;j++){
				ans+=money/m[j];
				money %= m[j];
			}
			
		}
		cout<<ans<<endl;

	}
	return 0;
}