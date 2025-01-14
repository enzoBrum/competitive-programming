#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

void kadane(int &ans, int &ans_l, int &ans_r, vector<int> &vec) {
  int cur = 0, cur_l = 0;

  for (int i = 0; i < vec.size(); ++i) {
    int num = vec[i];

    if (cur < 0)
      cur = num, cur_l = i;
    else
      cur += num;

    if (cur > ans ||
        (cur == ans && (cur_l < ans_l || (cur_l == ans_l && i < ans_r)))) {
      ans = cur;
      ans_l = cur_l;
      ans_r = i;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = 0, ans_l = 0, ans_r = 0;

  string s;
  cin >> s;

  vector<int> vec(s.size());
  for (int i = 0; i < vec.size(); ++i)
    vec[i] = s[i] == 'R' ? 1 : -1;
  kadane(ans, ans_l, ans_r, vec);
  for (int i = 0; i < vec.size(); ++i)
    vec[i] = s[i] != 'R' ? 1 : -1;
  kadane(ans, ans_l, ans_r, vec);

  cout << ans_l + 1 << ' ' << ans_r + 1 << '\n';
}
