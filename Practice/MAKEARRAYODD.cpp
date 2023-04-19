#include <iostream>
using namespace std;

int main() {
	int t, n, x, even, odd;
	cin >> t;
	while(t--){
	    even = odd = 0;
	    cin >> n >> x;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	        if(arr[i]&1){
	            odd++;
	        } else even++;
	    }
	    if(x&1){
	        cout << (even/2 + even%2);
	    } else if(odd){
	        cout << even;
	    } else cout << -1;
	    
	    cout << endl;
	    
	}
	return 0;
}
