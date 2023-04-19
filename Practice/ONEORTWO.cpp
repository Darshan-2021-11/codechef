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
	int x, y; // x for Chef and y for Chefina
	cin >> x >> y;
	// Here's the deal, nobody wants their coin to be finished in game, so they
	// would only want to finish the other one's coins first, so they will
	// always want to take one of the coin from their pile and one from other
	// one's pile
	//
	// declare a flag, if chef wins, its true else false
	bool flag = false;
	//	if(x-y >= 2) flag = true;
	//	else if((abs(x-y) < 2) && min(x,y) & 1) flag = true;
	if((x-y >= 2) || ((abs(x-y) < 2) && min(x,y) & 1)) flag = true;

	if(flag) cout << "CHEF";
	else cout << "CHEFINA";

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
