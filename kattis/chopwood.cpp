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

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<bool> removed(n, false);
  vector<int> cnt(n, 0), v_col(n);

  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    num--;
    cnt[num]++;
    v_col[i] = num;
  }
  for (int i = 0; i < n; ++i)
    pq.push({cnt[i], i});

  vector<int> ans;
  bool suc = true;
  int idx = 0;
  while (!pq.empty() && suc && idx < n) {
    auto [c, u] = pq.top();
    pq.pop();

    if (removed[u])
      continue;

    if (c) {
      suc = false;
      continue;
    }

    removed[u] = true;
    int v = v_col[idx++];
    pq.push({--cnt[v], v});
    ans.push_back(u);
  }

  if (!suc || idx != n)
    cout << "Error\n";
  else {
    for (auto &a : ans)
      cout << a + 1 << '\n';
  }
}
