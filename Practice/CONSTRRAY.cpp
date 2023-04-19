#include <iostream>
using namespace std;

int main() {
	long long int t, n, k1, k2, f;
	cin >> t;
	while(t--){
	    cin >> n;
	    if(n & 1){ cout << -1 << endl; continue; }
	    long long int a[n];
	    k1=0, k2=n-1, f=-1;
	    for(long long int i=0; i<n; i++){
	        if(i & 1){ a[k1++] = 2*i; }
	        else if(i & 2) { a[k2--] = 2*i; }
	        else if(i & 3) { a[k1++] = 2*i; }
	        else { a[k2--] = 2*i; }
	    }
	    for(int i=0; i<n; i++){
	        if(i&1) a[i] = -a[i];
	        cout << a[i] << " ";
	    }
	    cout << endl;
	    
	}
	return 0;
}
