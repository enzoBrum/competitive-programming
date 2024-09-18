#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int b, k, g;
  cin >> b >> k >> g;

  int k_per_g = k / g;
  b--;
  cout << ceil((double)b/k_per_g) << '\n';
}
