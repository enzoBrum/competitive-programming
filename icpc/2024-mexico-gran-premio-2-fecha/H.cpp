#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set                                                            \
  tree<int, null_type, less<int>, rb_tree_tag,                                 \
       tree_order_statistics_node_update>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, r, c;
  cin >> n >> r >> c;

  ordered_set tr;
  for (int i = 1; i <= n; ++i)
    tr.insert(i);
  vector<int> hired;

  int s1 = -1;
  int sn = n;

  // r--, c--;
  while (tr.size() > 2) {
    s1 = (s1 + r) % (int)tr.size();
    sn = ((int)tr.size() + ((sn - c) % (int)tr.size())) % (int)tr.size();

    int before_s, after_sn;
    if (s1 == 0) {
      if (sn == tr.size() - 1)
        before_s = *next(tr.rbegin());
      else
        before_s = *tr.rbegin();
    } else {
      if (sn == s1 - 1) {
        if (sn == 0)
          before_s = *tr.rbegin();
        else
          before_s = *tr.find_by_order(s1 - 2);
      } else {
        before_s = *tr.find_by_order(s1 - 1);
      }
    }

    if (sn == tr.size() - 1) {
      if (s1 == 0)
        after_sn = *(next(tr.begin()));
      else
        after_sn = *tr.begin();
    } else {
      if (s1 == sn + 1) {
        if (s1 == tr.size() - 1)
          after_sn = *tr.begin();
        else
          after_sn = *tr.find_by_order(sn + 2);
      } else {
        after_sn = *tr.find_by_order(sn + 1);
      }
    }

    // cout << tr.size() << '\n';
    if (s1 == sn) {
      // cout << "S1: " << s1 << ", SN: " << sn << '\n';
      auto h1 = tr.find_by_order(s1);
      // cout << "H1: " << *h1 << '\n';
      hired.push_back(*h1);
      tr.erase(h1);
      // s1 = (s1 + 1) % tr.size();
    } else {
      // cout << "S1: " << s1 << ", SN: " << sn << '\n';
      auto h1 = tr.find_by_order(s1);
      auto hn = tr.find_by_order(sn);
      // cout << "H1: " << *h1 << ", HN: " << *hn << '\n';
      tr.erase(h1);
      tr.erase(hn);
    }

    s1 = tr.order_of_key(before_s);
    sn = tr.order_of_key(after_sn);
  }

  for (auto &c : tr)
    hired.push_back(c);

  sort(hired.begin(), hired.end());
  for (auto &h : hired)
    cout << h << ' ';
  cout << '\n';
}
