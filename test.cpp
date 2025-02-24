#include <bits/stdc++.h>
#include <sstream>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  int mask = (1 << k) - 1, r, c;
  vector<int> vec(20);
  iota(all(vec), 1);

  set<int> seen;
  while (mask <= (1 << n) - (1 << (n - k))) {
    if (seen.count(mask)) {
      cout << "WRONG!!!!\n";
      return 0;
    }
    seen.insert(mask);

    stringstream ss;
    for (int i = 0; i < 21; ++i)
      if (mask & (1 << i))
        ss << vec[i] << ", ";
    string buf = ss.str();
    buf.pop_back();
    buf.pop_back();

    cout << buf << endl;

    c = mask & -mask, r = mask + c, mask = r | (((r ^ mask) >> 2) / c);
  }
  
  cout << "CNT: " << seen.size() << '\n';
}
