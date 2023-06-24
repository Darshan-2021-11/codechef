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

int const MOD = 1e9 + 7;

int solve() {
	int n, even_nos = 0, odd_nos = 0, total_subsets = 0;
	cin >> n;

	int a[n];

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for(int i = 0; i < n; i++) {
		if(a[i] % 2 == 0) {
			even_nos++;
			total_subsets = ((ll)total_subsets + even_nos) % MOD;
		} else {
			odd_nos++;
			if (odd_num % 2 == 0) {
				total_subsets = ((ll)total_subsets + even_nos) % MOD;
				even_nos++;
			}
		}
	}

	cout << total_subsets << '\n';
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

