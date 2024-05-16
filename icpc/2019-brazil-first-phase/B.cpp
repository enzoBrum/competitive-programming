#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n; cin >> n;
  
  int carlos;
  cin >> carlos;
  
  for (int i = 0; i < n - 1; ++i) {
    int v; cin >> v;
    if (v > carlos) {
      cout << "N\n";
      return 0;
    }
  }
  
  cout << "S\n";
  
}
