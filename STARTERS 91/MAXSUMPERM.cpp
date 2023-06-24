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
	int n, q, t1, t2, startLim = n, endLim = 0, index;
	ll x = 0;
	cin >> n >> q;
	index = n - 1;

	int a[n], b[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b, b+n);

	map <int, int> m1, m2;

	for (int i = 0; i < q; i++) {
		cin >> t1 >> t2;
		if(t1 < startLim) {
			startLim = min(startLim, t1 - 1);
		}
		if(t2 > endLim) {
			endLim = max(endLim, t2 - 1);
		}
		for (int j = t1 - 1; j < t2; j++) {
			m1[j]++;
		}
	}

	for (auto i: m1) {
		m2[i.second] = i.first;
	}

	for (auto i: m2) {
		a[i.second] = b[index];
		x += b[index--]*(i.first);
	}

	for (int i = 0; i < startLim; i++) {
		a[i] = b[index--];
	}

	for (int i = endLim; i < n; i++) {
		a[i] = b[index--];
	}

	cout << x << '\n';
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

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
