#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;

int d[501][501];
int p[501][501];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  memset(d, 63, sizeof d);
  memset(p, 63, sizeof p);
  int n;

  unordered_map<string, int> si;
  vector<string> is;
  
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string c;
    cin >> c;

    si[c] = si.size();
    is.push_back(c);
  }
  
  for (int i = 0; i < n; ++i) {
    string s;
    int num;
    cin >> s >> num;
    cin.ignore(1024, '\n');
    
    for (int j = 0; j < num; ++j) {
      string buf;
      getline(cin, buf);
      
      stringstream ss;
      ss << buf;
      ss>>buf;

      while (ss >> buf) {
        if (buf.back() == ',')
          buf.pop_back();
        d[si[s]][si[buf]] = 1;
        p[si[s]][si[buf]] = si[s];
      }
    }
  }
  
  for (int k = 0; k < n; ++k)
    for (int u = 0; u < n; ++u)
      for (int v = 0; v < n; ++v)
        if (d[u][v] > d[u][k] + d[k][v]) {
          d[u][v] = d[u][k] + d[k][v];
          p[u][v] = p[k][v];
        }
  
  //for (int i = 0; i < n; ++i)
  //  cout << is[i] << " -> " << d[i][i] << endl;
  int shortest_cycle = 0;
  for (int i = 1; i < n; ++i)
    if (d[i][i] < d[shortest_cycle][shortest_cycle])
      shortest_cycle = i;
  if (d[shortest_cycle][shortest_cycle] < 1e9) {
    int cur = shortest_cycle;
    vector<string> ans;
    do {
      ans.push_back(is[cur]);
      cur = p[shortest_cycle][cur];
    } while (cur != shortest_cycle);
    for (auto it = ans.rbegin(); it != ans.rend(); ++it)
      cout << *it << ' ';
    cout << '\n';
  } else {
    cout << "SHIP IT\n";
  }
}
