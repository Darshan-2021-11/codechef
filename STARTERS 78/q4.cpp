#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
	int n, x;
	cin >> n >> x;
	// `n` is the length of the string to be made, where `n+1` 1's will be
	// inserted. So the max and min value of `x` cannot be more than `n+1`
	//  and `-(n+1)` respectively
	//
	//  n>= -x+1 gives correct condition for negative numbers and for positive
	//  number, the case would be short circuited.
	//
	// if `x` is negative, then it must consists of `-` and `*`, and ignoring
	// `+` completely, similarly
	// if `x` is positive, we use `+` and `*` ignoring `-` totally
	vector <char> expression;
	if(x <= 0){
		int t = -1*x;
		//	cout << x << " " << t << " ";
		t++;
		//	cout << t << " ";
		if(t > n){
			cout << -1 << "\n";
			return 0;
		}
		expression.push_back('-');
		for (int i = 1; i < n; i++) {
			if(x) {
				expression.push_back('-');
				x++;
			}
			else expression.push_back('*');
		}
	} else { // x > 0 case
		if(x>n+1){
			cout << -1 << "\n";
			return 0;
		}
		x--;
		for (int i = 0; i < n; i++) {
			if(x) {
				expression.push_back('+');
				x--;
			}
			else expression.push_back('*');
		}
	}

	for(auto i:expression){
		cout << i;
	}
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
