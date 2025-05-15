#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;

int matrix[151][151];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m, q;
  while (cin >> n >> m >> q && (n || m || q)) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        matrix[i][j] = INF;
    
    while (m--) {
      int u, v, w;
      cin >> u >> v >> w;
      
      
      matrix[u][v] = min(matrix[u][v], w);
    }
    
    for (int k = 0; k < n; ++k)
      for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
          if (matrix[u][k] < INF && matrix[k][v] < INF)
            matrix[u][v] = min(matrix[u][v], matrix[u][k] + matrix[k][v]);
    
    while (q--) {
      int u, v;
      cin >> u >> v;
      
      bool neg_cycle = false;
      for (int k = 0; k < n && !neg_cycle; ++k)
        if (matrix[u][k] < INF && matrix[k][v] < INF && matrix[k][k] < 0)
          neg_cycle = true;

      if (neg_cycle)
        cout << "-Infinity\n";
      else if (matrix[u][v] == INF && u != v)
        cout << "Impossible\n";
      else
        cout << (u == v ? 0 : matrix[u][v]) << '\n';
    }
    cout << '\n';
    
  }
}
