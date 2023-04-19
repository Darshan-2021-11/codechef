#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
// #include <bits/stdc++.h>
#include "bits/stdc++.h"
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
	int n;
	cin >> n;
	// bishops are placed in zig-zag pattern in n*n matrix in the first two
	// rows(by inspections that there are exactly n-bishops placed in zig-zag
	// manner); hence if the number is odd, there is one extra step to move one
	// bishop out of the other, including the correct placement of the
	// currently moved bishop and move the backward bishop that is not in order.

	// 1st bishop(1,1) is correctly placed...
	// 2nd bishop is well placed for n=2, else we need to move it only one
	// time to the very end(n,n)
	// 3rd bishop is only to be moved to the centre
	// 4th bishop moves 2 times, once to the diagonal and once to the other
	// diagonal space to make space for the 4th bishop
	//
	// After this every subsequent bishop moves(if n is odd adds another 2 and
	// if n is even, adds another 1 to it)
	//
	if(n==1 || n==2) cout << 0;
	else if(n == 3) cout << 2;
	else if(n&1){
		// if n is odd, an extra one is added for the given logic, while if n
		// is divisible by 2(which is actually original n-3), then we increment
		// by 1 and then by 2 or totally by 3
		//
		// The below code does not work since the actual `n` needs to be odd to
		// add 1 and actual `n` to be even to add 2
		//
		// Hence we add 1 to n before checking its even or not
		//
		// NOTE THIS FORMULA COMPLETELY WORKS AND ALSO GIVES THE CORRECT
		// ANSWER:: JUST THAT I SUBMITTED THIS LATE AND GOT CONTEST OVER WHERE
		// DANGER LEVELS KICKED IN AND I COPIED SOMEONE ELSE WITH THE ODD AND
		// EVEN DIFFERENT CASES WITH INTERPOLATED ANSWER :(
		//	cout << 3 + ((n-3)/2)*3 - (n&1);
		//
		//	except if the original `n` is even... Only one move is required
		//
		//
		//	THIS FORMULA HOWEVER WE GET FROM THE VALUES OF THE BISHOP MOVES
		//	AFTER INTERPOLATION:
		//	1->0
		//	2->0
		//	3->2
		//	4->3
		//	5->5
		//	6->6
		//	7->8
		//	8->9
		//	9->11
		//	10->12
		//	AND SO ON...
		cout << (n/2)*3 -1;
	}
	else{
		cout << (n/2)*3 -3;
	}
	cout << "\n";

	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TET = 1e9;
	cin >> TET;
	for (int i = 1; i <= TET; i++) {
		if (solve()) {
			break;
		}
		#ifdef ONPC
			cout << "__________________________" << "\n";
		#endif
	}
	#ifdef ONPC
		cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC <<
		"second(s)" << "\n";
	#endif
}
