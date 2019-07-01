#include <iostream>
#include <vector>

using namespace std;


int main() {
	
	int n;
	int cows[55]={1,2,3,4};
	for(int i = 3; i<55; i++){
		cows[i]=cows[i-3]+cows[i-1];
	}
	while(cin>>n){
		cout<<cows[n]<<endl;
	}


	return 0;
}
