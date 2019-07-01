#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int m,n;
	
	while(cin>>m>>n){
		long long s[m][n];
		long long mx;
		int x,y;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>s[i][j];
			}
		}
		mx = s[0][0];
		x=0;y=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(abs(s[i][j])>abs(mx)){
					mx = s[i][j];
					x=i;y=j;
				}
			}
		}
		cout<< x+1 <<" "<< y+1 <<" "<<mx<<endl;
	}
	return 0;
}
