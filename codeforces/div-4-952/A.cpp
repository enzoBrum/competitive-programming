#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  while (t--) {
    string a, b;
    cin >> a >> b;

    swap(a[0], b[0]);
    cout << a << ' ' << b << '\n';
  }
}
