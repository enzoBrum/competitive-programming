#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

ll excluded_sum = 0;
vector<int> vec;
vector<char> used;

void backtrack(int k, ll cur, int depth, int last = -1) {
  if (k == depth) {
    if (cur < 200)
      excluded_sum += cur;
    return;
  }

  for (int i = last + 1; i < vec.size(); ++i) {
    if(used[i])
      continue;
    used[i] = true;
    backtrack(k+1, cur + vec[i], depth, i);
    used[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  vec.resize(n);
  used.assign(n, false);
  ll total_sum = 0;
  for (auto& v : vec)
    cin >> v, total_sum += (v * (1ll << (n-1)));
  
  for (int i = 0; i < 4; ++i)
    backtrack(0, 0, i+1);
  
  cout << total_sum - excluded_sum << '\n';
}
