#include <bits/stdc++.h>
using namespace std;
typedef ll long long

int solve() {
  int w, l; bool flag = false;
  cin >> w >> l;
  if(w == 1 || l == 1) {
    if(w > 1 || l > 1) flag = true;
  } else if(w == 3 && l == 3) {
    flag = false;
  } else if(w==2 && l == 2) {
    flag = false;
  } else flag = true;

  if(flag) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}

int main() {
  int t;
  while(t--) solve();

  return 0;
}
