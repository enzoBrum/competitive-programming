#include <iostream>
#include <vector>

using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x;
  cin >> n >> x;

  vector<int> vec(n);
  for (auto &h : vec)
    cin >> h;

  int ans = 1;
  int curr = 1;

  for (int i = 1; i < vec.size(); ++i) {
    if (vec[i] - vec[i - 1] <= x) {
      curr++;
    } else {
      ans = max(ans, curr);
      curr = 1;
    }
  }
  // if (vec.back() - vec[vec.size() - 2] <= x)
  //   curr++;

  ans = max(ans, curr);

  cout << ans << '\n';
}

