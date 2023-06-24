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
	int n, m, h;
	ll max_capacity = 0, tmp;
	cin >> n >> m >> h;

	int a[n], b[m];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	sort(a, a + n);
	sort(b, b + m);

	if (n >= m) {
		int mi = 0;
		for (int i = n - m; i < n; ++i) {
			tmp = 1ll * b[mi] * h;
			max_capacity += (1ll * a[i]) > tmp ? tmp : a[i];
			++mi;
		}
	}
	else {
		int ni = 0;
		for (int i = m - n; i < m; ++i) {
			tmp = 1ll * b[i] * h;
			max_capacity += (1ll * a[ni]) > tmp ? tmp : a[ni];
		}
	}

	cout << max_capacity << '\n';
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
