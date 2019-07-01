#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		char s[55];
		bool ans=true;
		gets(s);
		for(int i=0;i<strlen(s);i++){
			if(i==0 && '0'<=s[0] && s[0]<='9'){
				ans = false;
				break;
			}
			else{
				if (!(('a'<=s[i] && s[i]<='z') || ('A'<= s[i]&& s[i]<= 'Z') || ('0'<=s[i] && s[i]<='9') || s[i]=='_')){
					ans = false;
					break;
				}
			}
		}
		cout<<(ans?"yes":"no")<<endl;
		

	}
	return 0;
}