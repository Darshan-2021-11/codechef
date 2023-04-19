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
	// permutation subsequence
	int n;
	cin >> n;

	ll tmp, mod = 1000000007, perm_ss = 1;// permutation subsequence
	map <ll, ll> m;

	for (int i = 0; i < n; i++) {
		cin >> tmp;

		/*
		if(tmp <= perm_ss){
			m[tmp]++;

			// if tmp equal to perm_ss is found, increase its value by 1;
			// next time, it will be less than perm_ss for same tmp value
			if(tmp == perm_ss) perm_ss++;


			// test cases failed after the mod problem of ans variable was
			// solved... Then got the thought that let's say we get number 6
			// before 5, then this perm_ss thing will not work
			//
			// Better to add all input things into the map and then check for
			// consecutive numbers
		}
		*/
		m[tmp]++;
	}

	// now tmp will store number of permutation subsequence possible
	// for `n`th digit
	tmp = 1;
	ll ans = 0;
	for(auto &i: m){
		if(i.first == perm_ss++) {
			tmp = ((tmp % mod) * (i.second % mod)) % mod;
			// forgot to do modulo mod for ans variable failing test cases :(
			//	ans += tmp;
			ans = ((ans % mod) + (tmp % mod)) % mod;
		}
		else break;
	}

	cout << ans << "\n";
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
