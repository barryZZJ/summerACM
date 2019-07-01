#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char s[105];
	while(cin>>s){
		char mxch = 'a';
		for(int i=0; i<strlen(s); i++){
			if(s[i]>mxch){
				mxch = s[i];
			}
		}
		for(int i=0; i<strlen(s); i++){
			putchar(s[i]);
			if(s[i] == mxch) cout<<"(max)";
		}
		cout<<endl;
	}
	return 0;
}