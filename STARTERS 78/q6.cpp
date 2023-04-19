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

//	int solve() {
//		// 1<=n<=2*1e5 and 1<=k<=1e8
//		int n, solved = 0;
//		ll k, tmp;
//		cin >> n >> k;
//		vector <ll> st, bt;
//	
//		// taking input for solving time
//		for(int i=0; i<n; i++) {
//			cin >> tmp;
//			st.push_back(tmp);
//		}
//		// taking input for break time
//		for(int i=0; i<n; i++) {
//			cin >> tmp;
//			bt.push_back(tmp);
//		}
//		// create a multimap, where it stores multiple key values(if any), and
//		// sorts the keys in increasing order, here key is amount of time taken,
//		// and the value is the initial time of solving the problem
//		multimap <ll, ll> time;
//		for (int i = 0; i < n; i++) {
//			time.insert( pair <ll, ll> (st[i] + bt[i], st[i]));
//		}
//	
//	
//		// sorting to get the maximum number of questions chef can do, in minimum
//		// amount of time
//		//
//		// Also, one thing to note is that, the break time can also be more than
//		// solving the problem time, so we need to consider the sum of break time
//		// and solving time(only for questions that have been solved and going to
//		// the next question, this is helpful), for the edge case that the minimum
//		// solving time should also be considered at last for which sort the
//		// solving time too for check for it.
//		//
//		//	sort(st.begin(), st.end());
//		int min_st = *min_element(st.begin(), st.end()),
//			min_st_cnt = count(st.begin(), st.end(), min_st);
//	
//		// We consider the first element of sorted list each time, until we
//		// consider it already in finished questions with break time, after which
//		// we find it and delete it in the vector <ll> st;
//		//
//		// For implementing this, we use this method,
//		// 1) Take the smallest element in the sorted st vector.
//		// 2) Subtract the element and add the one having minimum total time, and
//		// remove the element(one having minimum total time) from the vector.
//		// 3) Repeat this until our vector is empty and the multimap iterator goes
//		// to the end, both happens simultaneously, so no problem in that.
//		//
//		// AFTER FAILING NEARLY ALL TEST CASES, GOT TO KNOW THAT WE NEED TO KEEP
//		// THE SMALLEST SOLVING TIME FOR THE VERY LAST EVEN THOUGH THAT ONE HAS THE
//		// LEAST SUM OF SOLVING.
//		//
//		// THIS ALSO MEANS WE DO NOT EVEN NEED TO DELETE THE ELEMENTS FROM st
//		// VECTOR, INFACT WE CAN ONLY USE THE `MIN` VALUE OF st AND NEVER USE IT IN
//		// INTERMEDIATE SUMS
//		
//		// Step 1
//		//
//		tmp = min_st;
//		// why we need tmpst to store the same thing as that of 1st element of st?
//		// ANS: When we are removing the element in st vector having the same value
//		// as the one on the iterator of time multimap->second; it is really
//		// possible that we may remove the first value of vector if its st and
//		// st+bt both are least, then the next time we subtract it from tmp, we
//		// remove a larger portion than the previous addition, which may lead to
//		// more questions solved.
//		
//		//	ll tmpst = st[0];
//	
//		if(tmp <= k){
//			solved++;
//		} else {
//			cout << 0 << "\n";
//			return 0;
//		}
//		// making an iterator for using the multimap
//		auto itT = time.begin();
//	
//		// the it != time.end(); takes care of the case where all the questions are
//		// solved and still free time `k` is left
//		//
//		// Step 3
//		while(solved && itT != time.end()){
//			// Step 2
//			//
//		//	// Also, we need to delete the element first before adding, since the
//		//	// 1st element of multimap and sorted st vector can be the same one
//		//	auto itS = find(st.begin(), st.end(), itT->second);
//		//	st.erase(itS);
//		//	// We do not need to sort the vector again after deleting since it is
//		//	// already in sorted order
//		//	//
//		//	// Finish the loop if no element present in st, i.e. all questions have
//		//	// been solved
//		//	WE ONLY NEED TO USE THE MIN_VALUE OF st VECTOR WHEN ITS COUNT IS MORE
//		//	THAN ONE
//		//
//		//
//		//	FINALLY FORGOT TO ADD THE CONSTRAINT OF THE MAP, IF IT REACHED THE END
//		//	OR NOT
//		//	but the problem is, even though itT reached time.end(), it still
//		//	somehow never gave the exception
//			if(!(min_st_cnt > 1)){
//				if(itT->second == min_st){
//					itT++;
//				}
//			}
//	
//			tmp += itT->first; 
//	
//			if(tmp <= k) {
//				solved++;
//				itT++;
//			} else break;
//		}
//		cout << solved << "\n";
//		return 0;
//	}

int solve() {
	// only thing we need to do different from previous approach is that, after
	// the value of `k` is reached by tmp, just search the entire multimap to
	// find a second element that can fit into the time `k`, before it was
	// reached
	//
	// 1<=n<=2*1e5 and 1<=k<=1e8
	int n, solved = 0;
	ll k, tmp, min_stI = 0;
	cin >> n >> k;
	vector <ll> st, bt;

	// taking input for solving time
	for(int i=0; i<n; i++) {
		cin >> tmp;
		st.push_back(tmp);
	}
	// taking input for break time
	for(int i=0; i<n; i++) {
		cin >> tmp;
		bt.push_back(tmp);
	}
	multimap <ll, ll> time;
	for (int i = 0; i < n; i++) {
jj\\		time.insert( pair <ll, ll> (st[i] + bt[i], st[i]));
	}

	tmp = 0;
	auto itT = time.begin();

	do {
		tmp += itT->first; 
		if(tmp <= k) {
			// minimum solving time means maximum break time, implemented in
			// next line
			min_stI = min(min_stI, itT->first - itT->second);
			solved++;
			itT++;
		} else {
			// two ways in which Chef can do more problems, if with the last
			// sum of tmp, any previous question, whose solving time is least,
			// its break time would be removed
			//
			// or we remove the last addition altogether that increases tmp
			// above `k` and check for the remaining elements left in multimap
			// for a solving time that incorporates the time limit
			if((tmp - min_stI) <= k) solved++;
			else {
				tmp -= itT->first;
				for(; itT != time.end(); itT++){
					if(tmp+itT->second <= k) {
						solved++;
						break;
					}
				}
			}
		break;
		}
	} while(solved && itT != time.end());

	cout << solved << "\n";

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
