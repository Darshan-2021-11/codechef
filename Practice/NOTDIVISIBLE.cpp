#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int t, n, i;
	cin >> t;
	while(t--){
	    cin >> n;
	    
	    /* this does not work and time limit exceeds
	    int arr[n];
	    
	    for(i=0; i<n; i++){
	        arr[i] = rand() % 600 - 300;
	    }
	    for(i=0; i<n; i++){
	        for(j=i+1; j<n; j++){
	            sum = 0;
	            for(k=i; k<j+1; k++){
	                sum += arr[k];
	            }
	            if(sum%(j-i+1) == 0){
	                arr[k] = (++arr[k] + 300) % 600 - 300;
	                i--;
	                j = i+1;
	            }
	        }
	    }
	    
	    for(i=0; i<n; i++){
	        if(i!=n-1) cout << arr[i] << " ";
	        else cout << arr[n-1] << endl;
	    }
	    */
        
        // the idea is never to let the sum be greater than the number it is gonna be divisible by and have different elements at adjacent elements to not get divisible
        for(i=0; i<n; i++){
            if(i%2){
                cout << 0 << " ";
            } else cout << 1 << " ";
        }
        cout << endl;
	}
	
	return 0;
}
