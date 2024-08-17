#include <bits/stdc++.h>
#include <string>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  vector<int> vec(n), die(7);
  for (auto& v : vec) {
    cin >> v;
    die[v]++;
  }
  
  int w = -1, wv = -1;
  for (int i = 0; i < vec.size(); ++i)
    if (die[vec[i]] == 1 && wv < vec[i]) {
      w = i;
      wv = vec[i];
    }
  cout << (w == -1 ? "none" : to_string(w+1)) << '\n';
  
}
