
#include <iostream>
using namespace std;

int main() {
	int t, a, b, c, d, t1, t2;
	cin >> t;
	while(t--){
	    cin >> a >> b >> c >> d;
	    
	    if(c>=a) t1=a;
	    else t1=c;
	    if(d>=b) t2=d;
	    else t2=b;
	    
	    if((b>=c&&d>=b) || (d>=a&&b>=d)){
	        cout << t2-t1+1;
	    }else cout << b-a+d-c+2;
	    cout << endl;
	}
	return 0;
}
