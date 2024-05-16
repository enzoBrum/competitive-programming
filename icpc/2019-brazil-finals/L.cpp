#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include <functional>
#include<map>
#include<unordered_map>
#include<array>

using namespace std;
using pii = pair<int,int>;

// WTF?.?
// is this DP?

const int N = 1e6 + 1;
int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0); cout.tie(0);
  
  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> continuous(n, vector<int>(m));
  for (int i = 0;i < n;++i) {
    int begin = 0;
    continuous[i][0] = 0;
    char last; cin >> last;
    for (int j = 1; j < m; ++j) {
      char curr; cin >> curr;
      continuous[i][j] = curr == last ? continuous[i][j-1] : j;
      last = curr;
    }
  }
  
  vector<vector<pair<int, int>>> ret(n, vector<pair<int , int >>(m, {1,1}));
  
  for (int j = 0; j < m; ++j) 
    ret[0][j].second = j - continuous[0][j] + 1;
  
  pair<int,int> ans = {1,1};
  int square = 1;
  for (int i = 1; i < n; ++i) {
  	for (int j = 1; j < m; ++j) {
  	  int w = min(ret[i-1][j].second, j - continuous[i][j] + 1);
  	  int h = ret[i-1][j].first + 1;
  	  
  	  int w2 = min(j - continuous[i-1][j] + 1, j - continuous[i][j] + 1);
  	  int h2 = 2;
  	  
  	   /* 	  if (i >= 5 && i <= 7 && j >= 7) {
  	    printf("I=%d, J=%d\nh=%d, w=%d\nw2=%d,h2=%d\nhabove=%d\n\n", i, j, h, w, h2, w2, ret[i-1][j].first);
  	  }*/
  	  
  	  if (min(h2,w2) >= min(w,h)) {
  	    h = h2;
  	    w = w2;
  	  }
  	  if (w == 1) h = 1;
  	  ret[i][j] = {h, w};
  	  
  	  if ( min(h,w) > square ) {
  	    ans = ret[i][j];
  	    square = min(h,w);
  	  }
  	  

  	}
  }
  
  cout << square*square << '\n';
}

