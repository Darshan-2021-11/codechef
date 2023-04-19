#include <stdio.h>
/*
#include <stdlib.h>
#include <math.h>
*/

int main(void) {
	int t, N;
	scanf("%d", &t);
	
	while(t--){
	    scanf("%d", &N);
	    
	    char arr[N+1];
	    scanf("%s", arr);
/* 1st attempt, was very simple and did not fulfill all cases

        int value, count, temp, flag=1;

	    // This converts the char array to int, but does not convert binary but decimal
	    // value = atoi(arr);
	    
	    // So we use this technique
	    value = 0;
	    count = 0;
	    for(int i=0; i<N; i++) {
	        value <<= 1;
	        if(arr[i] == '1'){
	            value += 1;
	        }
	    }
	    // printf("%d %d\n", value, N);
	    temp = 1; temp <<= N-1;
	    
	    // this does not work for the case of 9
	    for(int i=temp1; (i>=0) && flag; i++){
	        while((value >= temp2) && flag){
	            value -= temp2;
	            count++;
	            if(count==3) flag = 0;
	        }
	        temp2 >>= 1;
	    }
	    if(!value) printf("YES\n");
	    else printf("NO\n");

*/


        // counts number of zeros and once in the input string
        int count0 = 0, count1 = 0;
        for(int i=0; i<N; i++){
            if(arr[i] == '1') count1++;
        }
        count0 = N - count1;
        
        // if the number of 1's in binary string is equal to 3, then it can be expressed as sum of powers of 2, exactly like binary nummber system
        // else if number of 1's is equal to 2 and contains at least one zero, the case of 8 can be used i.e.
        // 9 = (1001)2 can also be written as sum of 9 = 1 + (100 + 100) // the sum in parenthesis being equivalent to 1000
        
        // note that we can do this multiple times until we get to a result of sum of three powers of 2 e.g. 8 = (100)2 = (10)2 + (10)2 = (10)2 + (1)2 + (1)2
        
        // also note that if count1 == 2 and count2 == 0, then also (11)2 = (1)2 + (1)2 + (1)2, so technically we do not need 0 if count1 == 2
        if(count1==3 || count1 == 2 || (count1 == 1 && count0 > 1)){
            printf("YES\n");
        } else printf("NO\n");
	}
	
	return 0;
}

