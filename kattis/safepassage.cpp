#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;
int memo[1 << 15][2];
int N;
int people[15];
bool visited[1 << 15][2];
stack<string> st;

int solve(int mask, int pos) {
  if (memo[mask][pos] < INF) {
    // bitset<5> b(mask);
    // stringstream ss;
    // ss << pad << '(' << b.to_string() << ", " << pos << ")=" <<
    // memo[mask][pos]
    //    << endl;
    // st.push(ss.str());
    return memo[mask][pos];
  }
  if (visited[mask][pos]) {
    return INF;
  }

  // bitset<5> b(mask);
  // cout << pad << '(' << b.to_string() << ", " << pos << ")\n";

  visited[mask][pos] = true;
  int ans = 1e9;
  for (int i = 0; i < N; ++i) {
    int m = mask & (1 << i);
    if (m > 0 && pos == 1)
      ans = min(ans, people[i] + solve(mask - (1 << i), 1 - pos));
    else if (m == 0 && pos == 0)
      ans = min(ans, people[i] + solve(mask + (1 << i), 1 - pos));
    else
      continue;
    for (int j = i + 1; j < N; ++j) {
      int m2 = mask & (1 << j);
      if (m > 0 && pos == 1 && m2 > 0)
        ans = min(ans, max(people[i], people[j]) +
                           solve(mask - (1 << i) - (1 << j), 1 - pos));
      // else if (m == 0 && pos == 0 && m2 == 0)
      //   ans = min(ans,
      //             max(people[i], people[j]) +
      //                 solve(mask + (1 << i) + (1 << j), 1 - pos, pad + " "));
    }
  }
  // if (ans < INF) {
  //   bitset<5> b(mask);
  //   stringstream ss;
  //   ss << pad << '(' << b.to_string() << ", " << pos << ")=" << ans << endl;
  //   st.push(ss.str());
  // }
  return memo[mask][pos] = ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(memo, 63, sizeof memo);
  memset(visited, 0, sizeof visited);
  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> people[i];
  memo[0][0] = 0;
  cout << solve((1 << N) - 1, 1) << endl;
  // while (!st.empty()) {
  //   cout << st.top();
  //   st.pop();
  // }
}
