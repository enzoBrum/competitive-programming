#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<string> area = {"", "single", "double", "triple"};
  for (int a = 0; a <= 3; ++a)
    for (int b = 0; b <= 3; ++b)
      for (int c = 0; c <= 3; ++c)
        for (int i = 1; i <= 20; ++i)
          for (int j = 1; j <= 20; ++j)
            for (int k = 1; k <= 20; ++k) {
              if (a * i + b * j + c * k != n)
                continue;

              if (a)
                cout << area[a] << ' ' << i << '\n';
              if (b)
                cout << area[b] << ' ' << j << '\n';
              if (c)
                cout << area[c] << ' ' << k << '\n';
              return 0;
            }
  cout << "impossible\n";
}
