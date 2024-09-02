#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int w[3], h[3];


bool solve() {
  // Left
  if (h[0] == h[1] + h[2] && w[0] + w[1] == h[0] && w[1] == w[2])
    return true;
  // Down
  return w[0] == w[1] && w[0] == w[2] && h[0] + h[1] + h[2] == w[0];
}

bool backtrack(int i) {
  if (i == 3)
    return solve();

  if (backtrack(i+1))
    return true;
  swap(h[i], w[i]);
  if (backtrack(i+1))
    return true;
  swap(h[i], w[i]);
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for (int i = 0; i < 3; ++i)
    cin >> h[i] >> w[i];

  cout << (backtrack(0) ? "YES\n" : "NO\n");
}
