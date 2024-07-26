#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int c, n;
  cin >> c >> n;

  priority_queue<int, vector<int>, greater<int>> pq;
  int ans = 0;
  while (n--) {
    int t, d;
    cin >> t >> d;

    if (pq.size() == c) {
      if (pq.top() > t + 20)
        ans++;
      t = pq.top();
      pq.pop();
    }

    pq.push(t + d);
  }

  cout << ans << '\n';
}
