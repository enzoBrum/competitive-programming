#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dp[1001][41];
int p[1001][41];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int l, w;
  cin >> l >> w;
  
  memset(p, -1, sizeof(p));
  
  dp[0][0] = 1;

  for (int weight = 1; weight <= w; ++weight)
    for (int num_letters = 1; num_letters <= l; ++num_letters)
      for (int letter = 1; letter <= 26; ++letter)
        if (weight - letter >= 0 && dp[weight - letter][num_letters-1])
          dp[weight][num_letters] = 1, p[weight][num_letters] = weight - letter;
  
  if (!dp[w][l]) {
    cout << "impossible\n";
    return 0;
  }
  
  int cur_w = w;
  int cur_len = l;
  
  while (cur_w) {
    int prev_w = p[cur_w][cur_len];

    cout << (char)('a' + cur_w - prev_w - 1);
    cur_w = prev_w;
    cur_len--;
  }
  cout << '\n';

}
