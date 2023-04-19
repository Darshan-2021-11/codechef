#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
// #include <bits/stdc++.h>
#include "bits/stdc++.h"
#define sz(a) ((int)((a).size()))
// #define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
	int n, k;

	map<int, int> m;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		m[-c]++;
	}

	int max_rep = INT_MIN, min_rep = INT_MAX;
	for(auto & it: m){
		max_rep = max(max_rep, it.second);
		min_rep = min(min_rep, it.second);
		//	cout << (char)-it.first << " " << it.second << " ";
	}
	//	cout << endl;

	// if the highest frequency character is more than k added with minimum
	// frequency character, then the answer would be invalid since the absolute
	// difference of frequency of any two character cannot be more than that of
	// `k`.
	if(max_rep - min_rep <= k){
//		DOES THE WORK [V]; LEXICOGRAPICAL ORDER [X];
//
//		for (int i = 0; i < min_rep; i++) {
//			for(auto & it: m){
//				cout << it.first;
//			}
//		}
//		for(auto & it: m){
//			while(it.second-- != min_rep){
//				cout << it.first;
//			}
//		}
//		cout << "\n";
		
	// I'LL TRY TO DO IT FROM THE START AS IT IS HARD TO THINK ABOUT, EASY
	// APPROACH WOULD BE FOLLOW THE RULES OF SUFFIX AND MAKE STRING, THEN
	// REVERSING IT
	//
	// Approach: 1. Print all the character in for loop(once), for each
	// character from k to >1, which acts as balancing the frequency.
	// 2. This ensures to print all the characters in lexicographical order by
	// using the for loop, k and m.second, and deals with the maximum occuring
	// character at the end while loop.
	// 3. Remove all the large valued characters first from the map, and remove
	// the less values ones at the very last and reverse it.
	//
	// OBSERVATION: Take point 3 seriously since max_rep - min_rep <= k, we can
	// use this fact.
	//
	// THIS HURTS MY BRAIN, I AM TRYING FROM THE END

		vector <char> ans(n);
		int freq = 0;
		for(auto it = m.begin(); it != m.end() && freq != n; it++) {
			int t = 0;
			auto tmpit = m.begin();
			// We need elements always smaller than this to insert once
			for(; tmpit != it; tmpit++){
				if(tmpit != it && tmpit->second > 0){
					ans.push_back(-tmpit->first); freq++; tmpit->second--;
					//	cout << (char)-tmpit->first << tmpit->second;
				}
			}
			// printing tmp `k` times the first time it appears
			while((t++ < k) && (it->second > 0)) {
				ans.push_back(-it->first); freq++; it->second--;
				//	cout << (char)-it->first << it->second;
			}
			tmpit++; // excluding `it` from for loop
			// We need elements always smaller than this to insert once
			for(; tmpit != m.end(); tmpit++){
				if(tmpit != it && tmpit->second > 0){
					ans.push_back(-tmpit->first); freq++; tmpit->second--;
					//	cout << (char)-tmpit->first << tmpit->second;
				}
			}
		}
		reverse(ans.begin(), ans.end());

		for(char & i: ans){
			cout << i;
		}

	} else { cout << -1; }
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
