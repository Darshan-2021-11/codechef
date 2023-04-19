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
	int n, tmp; // number of balls
	cin >> n;
	vector <int> runs;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		runs.push_back(tmp);
	}

	// formula of strike rate = (no. of runs)/ (no. of balls played) * 100
	// if runs = balls played, strike rate is reached exactly 100
	//
	// Approach: Calculate the sum of runs for each elements in array of runs,
	// if it becomes == n, increment the number of times strike rate reached
	// stored in `sr100` variable

	tmp = 0;
	int sr100 = 0; // stores number of times strike rate reaches 100
	for (int i = 1; i <= n; i++) {
		tmp += runs[i-1];
		if(tmp == i) sr100++;
	}
	cout << sr100 << "\n";
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
