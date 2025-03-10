#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int memo[5001][5001];
string a, b;

int solve(int i, int j) {
  if (i < 0)
    return j+1;
  if (j < 0)
    return i+1;
  if (i == 0 && j == 0)
    return a[i] != b[j];

  if (memo[i][j] != -1)
    return memo[i][j];

  int ans =
      min(min(min(solve(i, j - 1), solve(i - 1, j)), solve(i - 1, j - 1)) + 1,
          a[i] == b[j] ? solve(i - 1, j - 1) : (int)1e9);

  return memo[i][j] = ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(memo, -1, sizeof memo);

  cin >> a >> b;
  if (a.size() < b.size())
    swap(a, b);
  
  cout << solve(a.size() - 1, b.size() - 1) << '\n';
}
