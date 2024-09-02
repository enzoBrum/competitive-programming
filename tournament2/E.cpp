#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, k;
  cin >> a >> b >> k;

  for (int i = 1; i <= k; ++i)
    cout << a*i + b << ' ';
  cout << '\n';
}
