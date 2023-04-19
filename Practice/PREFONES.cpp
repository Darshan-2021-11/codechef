#include <iostream>
using namespace std;

int main() {
	int t, n, f, r, tmp;
	cin >> t;
	while(t--){
	    f = r = tmp = 0;
	    cin >> n;
	    char a[n+1];
	    cin >> a;
	    char *c = a;
	    while(*c++ == '1') f++;
	    while(*c !='\0'){
	        while(*c++ == '1') tmp++;
	        if(tmp > r) r = tmp;
	        tmp = 0;
	    }
	    cout << f+r << endl;
	}
	return 0;
}
