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

	string s;
	map <string, int> programs;
	map <int, string> alt_tab_seq;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		// s = s.substr((int)size(s) - 2, 2);
		programs[s] = i;
	}

	for (auto i: programs) {
		alt_tab_seq[i.second * (-1)] = i.first.substr((int)size(i.first) - 2, 2);
	}

	for (auto i: alt_tab_seq) {
		cout << i.second;
	}
	cout << '\n';

	return 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TET = 1;
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

