#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
	// We need to find values of a,b,c and d such that a given number `n`,
	// ((a&b)|c)^d = N
	//
	// We will use two things to find the values of a, b,c and d, 
	// suppose a number `M`, then M&M = M, M|M = M
	//
	// Consider other thing that there are two numbers `P` and `Q`, then
	// (P^Q)^Q negates the effect of XOR on P and the expression becomes
	// (P^Q)^Q = P;
	
	// This means if we want `N` as the answer, we can take any number `M`
	// such that ((M&M)| M)^ (N^M) = N; where a,b,c = M and d = N^M
	//
	// But the problem is we need a,b,c and d to be distinct.   :(
	//
	// No problem, we use some fixed different a,b,c and d such that the thing
	// holds
	// e.g. a = (100)2, b = (101)2, c = (001)2, such that 
	// (a&b) = (100)2, ((a&b)|c) = (101)2, setting this equal to d; i.e.
	// d = (101)2^N, we got our answer.
	//
	// ONLY PROBLEM IS, IF N=5, it would give the result as 0;
	//
	// We can use the fact that n<2^32 and we are using long long i.e. 64 bit,
	// if we use a number for a,b,c and d such that all are more than 2^32, we
	// win!
	//
	//
	// The final edge case that I was not able to discover, and seen from
	// answer of a different contestant is that, if `n` is 0; then we do not
	// get the final answer to be 0; so we use some fixed value of a,b,c and d
	// i.e. not dependent on `n`
	
	ll n, a = 0b0111111111111111111111111111111111111111
		, b = 0b1011111111111111111111111111111111111111
		, c = 0b1111111111111111111111111111111111111111
		, d;
	cin >> n;
	if(!n){
		cout << 0b001 << " " << 0b101 << " " << 0b110 << " " << 0b111;
		return 0;
	}
	d = c^n;
	// the problem with this is, when x=0, c^n = c^0 = c; where c and d becomes
	// same in value and the program fails.
	if((((a&b)|c)^d) == n)
		cout << a << " " << b << " " << c << " " << d << "\n";
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
