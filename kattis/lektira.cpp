#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s;
  cin >> s;
  
  string og_s = s;

  string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
  for (int i = 1; i < s.size() - 1; ++i) {
    for (int j = i+1; j < s.size(); ++j) {
      s = og_s;    
      
      reverse(s.begin(), s.begin() + i);
      reverse(s.begin() + i, s.begin() + j);
      reverse(s.begin() + j, s.end());
      
      if (s < ans)
        ans = s;
    }
  }
  cout << ans << '\n';
}
