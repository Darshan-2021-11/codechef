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
	string date, p[3];
	int i = 0, d, m;
	cin >> date;

	for (auto j: date) {
		if(j != '/')
			p[i].push_back(j);
		else i++;
	}

	d = stoi(p[0]);
	m = stoi(p[1]);
	// or take the something to take less conditions,
	// if m > 12, MM/DD/YYYY
	// else if d > 12, DD/MM/YYYY
	// else BOTH
	if(d <= 12 && m <= 12) cout << "BOTH\n";
	else if(d <= 12) cout << "MM/DD/YYYY\n";
	else if(m <= 12) cout << "DD/MM/YYYY\n";
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
