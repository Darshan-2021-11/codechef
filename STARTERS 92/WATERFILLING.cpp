#include <bits/stdc++.h>
using namespace std;

int solve() {
  int b1, b2, b3, count = 0;
  cin >> b1 >> b2 >> b3;
  if(b1) count++;
  if(b2) count++;
  if(b3) count++;

  if(count < 2) cout << "Water filling time\n";
  else cout << "Not now\n";
  return 0;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}
