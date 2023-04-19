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
	ll x, y, count = 0;
	vector<int> primes;
	cin >> x >> y;

	for(int i=2; i<sqrt(x)+1; i++){
		if(!(x%i)){
			// gets us factors
			primes.push_back(i);
			break;
			// even if j<2, primes will push_back 2;
			//
			//
			// NOTE:
			// Actually we can use the fact that the smallest factor(except 1)
			// of any number is always a prime
			/*
			for(int j=2; j<sqrt(i)+1; j++){
				// checks if factor is prime
				if((j%i) == 0){
					flag = false;
					break;
				}
			}
			// if prime, push_back to primes vector
			if(flag){
				primes.push_back(i);
				break;
			}
			*/
		}
	}
	// if no prime factors found in that range(2, sqrt(n)), the number is
	// itself a prime and we push it back to vector.
	if(!primes.size()) primes.push_back(x);
	if(x < y){
		primes.push_back(2);
		//	cout << primes.at(0) << " ";
		x += primes.at(0);
		//	cout << x << " ";
		// even if the smallest factor is any prime other than 2, in the very
		// next iteration, it(x) will become a factor of 2 and then the
		// smallest prime factor would be 2 if it wasn't already
		primes.erase(primes.begin());
		count++;
	}
	/* THIS IS CAUSING `TLE`
	 *
	while(x < y){
		x += primes.at(0);
		//	cout << x << " ";
		count++;
	}

	// Instead of adding to x, we simply divide the remaining part of `y` after
	// removing `x` and print the value
	*/
	if((y-x) & 1) count += ((y-x) >> 1) + 1;
	else count += ((y-x) >> 1);
	cout << count << "\n";
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
