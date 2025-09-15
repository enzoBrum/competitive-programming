#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int c;
  while (cin >> c && c) {
    unordered_map<string, int> mp;
    vector<vector<double>> d(c, vector<double>(c, INF));
    vector<vector<double>> d2(c, vector<double>(c, 0));
    
    for (int i = 0; i < c;  ++i) {
      string s;
      cin >> s;
      mp[s] = i;
    }
    
    int r;
    cin >> r;
    
    while (r--) {
      string a, b, ratio;
      cin >> a >> b >> ratio;

      int ia = mp[a], ib = mp[b];

      string na = ratio.substr(0, find(all(ratio), ':') - ratio.begin());
      string nb = ratio.substr(find(all(ratio), ':') - ratio.begin() + 1);
      
      int ra = stoi(na);
      int rb = stoi(nb);
      
      d[ia][ib] = (double)rb / ra;
      d2[ia][ib] = (double)rb / ra;
    }
    
    for (int i = 0; i < c; ++i)
      d[i][i] = d2[i][i] = 1;
    
    for (int k = 0; k < c; ++k)
      for (int i = 0; i < c; ++i)
        for (int j = 0; j < c; ++j)
            d[i][j] = min(d[i][j], d[i][k] * d[k][j]), d2[i][j] = max(d2[i][j], d2[i][k] * d2[k][j]);
    bool suc = true;
    for (int i = 0; i < c; ++i) {
      //cout << i << " -> " << d2[i][i] << endl;      
      //cout << i << " -> " << d[i][i] << endl;      
      if (d2[i][i] - 1 > 1e-6)
        suc = false;
    }
    if (suc)
      cout << "Ok\n";
    else
      cout << "Arbitrage\n";
  }
}
