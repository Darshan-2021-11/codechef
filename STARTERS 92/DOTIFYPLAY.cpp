#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n, k, l, tmp1, tmp2, maxLen = 0, index = 0;
  cin >> n >> k >> l;

  int mi[n] { 0 };

  for(int i=0; i < n; i++) {
    cin >> tmp1 >> tmp2;
    if(tmp2 == l) mi[index++] = tmp1;
  }

  if(index < k) {
    cout << -1 << '\n';
    return 0;
  }

  sort(mi, mi + n);

  while(k > 0){
    maxLen += mi[--n];
    k--;
  }
  
  cout << maxLen << '\n';

  return 0;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}
