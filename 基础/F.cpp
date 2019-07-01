#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int m,n;
		int tmp;
		int money=1;
		int ans=0;
		int pos=0;
		cin>>m>>n;
		for(int i=1;i<=n;i++){
			cin>>tmp;
			if(pos==0 && (tmp==1||i>=m)){
					pos = i;
			}

		}
		//cout<<"pos="<<pos<<endl;
		if(m==0){
			for(int i=1; i<=n; i++){
		
				ans += money;
				money*=2;

			}
			if(ans)
				cout<<ans<<"0000 RMB"<<endl;
			else
				cout<<"0 RMB"<<endl;
			continue;
		}
		
		if(pos)
		for(int i=pos+1; i<=n; i++){
		
			ans += money;
			money*=2;

		}

		
		if(ans)
			cout<<ans<<"0000 RMB"<<endl;
		else
			cout<<"0 RMB"<<endl;

	}
	return 0;
}