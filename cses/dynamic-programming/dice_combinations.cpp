#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  if (n == 1) {
    cout << "1\n";
    return 0;
  }

  vector<ll> ans(n + 1, 0);
  for (int i = 1; i <= 6 && i < ans.size(); ++i)
    ans[i] = 1;
  ans[0] = 0;

  for (int i = 2; i < ans.size(); ++i) {
    for (int j = 1; j <= 6 && i - j >= 0; ++j) {
      ans[i] += ans[i - j];
      ans[i] = ans[i] % ((ll)1e9 + 7);
    }
  }

  cout << ans.back() << '\n';
}
