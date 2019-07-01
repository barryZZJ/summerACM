#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int n,m;
	while(cin>>n>>m){
		int scores[n][m];
		double stusum[n];
		double stuaver[n];
		double subsum[m];
		double subaver[m];

		for(int i=0;i<m;i++) subsum[i]=0;

		for(int i=0;i<n;i++){
			stusum[i]=0;
			for(int j=0;j<m;j++){
				scanf("%d",&scores[i][j]);
//                cout<<"i="<<i<<"j="<<j<<endl;
//                cout<<"scores[i][j]="<<scores[i][j]<<endl;
				stusum[i] += scores[i][j];

				subsum[j] += scores[i][j];

			}
			stuaver[i] = stusum[i]/m;
		}
		for(int i=0;i<n;i++){
			printf("%.2f",stuaver[i]);
			if(i!=n-1) cout<<" ";
		}
		cout<<endl;


		for(int j=0;j<m;j++){
			subaver[j] = subsum[j]/n;
			printf("%.2f",subaver[j]);
			if(j!=m-1) cout<<" ";
		}
		cout<<endl;

		bool flag=false;
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(scores[i][j]<subaver[j]) flag=true;
			}
			if(!flag){
				cnt++;
			}
			flag=false;
		}

		cout<<cnt<<endl;
		cout<<endl;
	}


	return 0;
}
