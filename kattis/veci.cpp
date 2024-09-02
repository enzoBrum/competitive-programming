#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s;
  cin >> s;

  int best = 1e9;
  int og = stoi(s);
  do {
    int cur = stoi(s);
    if (cur > og && cur < best)
      best = cur;
  } while (next_permutation(s.begin(), s.end()));
  cout << (best == 1e9 ? 0 : best) << '\n';
}
