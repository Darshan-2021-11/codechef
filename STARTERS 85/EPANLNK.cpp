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
	// since n can be very large(upto 10^100), we take input as characters and
	// process the last 2 digits since 100 is divided by 20 and will not say
	// anything about remaining applications left
	//
	// since everyone decided to do exactly same number of applications
	//
	// This does not work and overflows
	//	ll tmp = (ll)7463749812302340912745859;
	//	cout << tmp;

	// applications = app
	string app;
	cin >> app;
	if(app.size() > 1)
		cout << ((app[app.size()-2]-48)*10 + (app[app.size()-1]-48)) % 20 << "\n";
	else cout << (app[0]-48) << "\n";
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
