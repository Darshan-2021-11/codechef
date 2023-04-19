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
	int n, tmp;
	cin >> n;
	map <int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		m[tmp]++;
	}
	if(!(n&1)){
		if(m[0] >= m[1]){
			if(m[1]) cout << m[0] - n/2;
			else cout << "-1";
		}
		else if(m[0] < m[1]){
			int tmp = (m[1]-m[0]);
			cout << tmp/2 + (tmp&1);
		}
		cout << "\n";
	}
	else cout << "-1\n";
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
