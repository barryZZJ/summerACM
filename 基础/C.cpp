#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int ans = 0;
		char s[1024];
		cin >> s;
		
		for(int i=0; i<strlen(s); i++){
			if (s[i] >= '0' && s[i] <= '9')
				ans++;
		}
		cout << ans << endl;
	}

	return 0;
}