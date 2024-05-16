#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include<unordered_map>
//#include<ctime>
#include<set>
#include<map>

using namespace std;
using pii = pair<int, int>;


int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  //cout.tie(0);
  
  
  int n, k;
  cin >> n >> k;
  
  
  struct Cmp {
    const string cards = "$A23456789DQJK";
    bool operator()(const pair<int, char>& a, const pair<int, char>& b) const {
    return a.first != b.first ? a.first < b.first : cards.find_first_of(a.second) < cards.find_first_of(b.second);
    };
  };
  vector<set<pair<int, char>, Cmp>> st(n);
  vector<map<char, int>> mp(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      char c;
      cin >> c;
      mp[i][c]++;
    }

    for (auto&[k, v] : mp[i])
      st[i].insert({v,k});
      
    if (i == k - 1)
      mp[i]['$'] = 1;
  }
  
  k--;
  
  bool can_use_wildcard = false;
  while (1) {
    int new_k = (k+1) % n;
          if (mp[new_k].size() == 1 && mp[new_k].begin()->second == 4) {
            k = new_k;
            break;
          }
 
    if (can_use_wildcard && mp[k].count('$')) {
      mp[k].erase('$');
      mp[new_k]['$'] = 1;
      can_use_wildcard = false;
    }  else {
      if (!can_use_wildcard && mp[k].count('$')) {
        can_use_wildcard = true;
      }
      auto it = st[k].begin();
      char c = it->second;
      st[k].erase(it);
      
      mp[k][c]--;
      
      if (mp[k][c] == 0)
        mp[k].erase(c);
      else
        st[k].insert({mp[k][c], c});
      
      if (mp[new_k].count(c)) {
        st[new_k].erase(st[new_k].find({mp[new_k][c], c}));
        mp[new_k][c]++;
        st[new_k].insert({mp[new_k][c],c});
      } else {
        mp[new_k][c] = 1;
        st[new_k].insert({1, c});
      }
    }
    
    if (mp[k].size() == 1 && mp[k].begin()->second == 4) {
     
         if (mp[new_k].size() == 1 && mp[new_k].begin()->second == 4) 
        k = min(k, new_k);
      break;
    }
          
    k = new_k;
      if (mp[new_k].size() == 1 && mp[new_k].begin()->second == 4) 
        break;
    
    /*
    for (int i = 0; i < n; ++i) {
      if (mp[i].count('$'))
        cout << '$';
      for (auto&[d,c] : st[i])
        for (int j = 0; j < d; ++j)
          cout << c;
      cout << '\n';
    }
    //sleep(1);
    */
    
    
  }
  
  for (int i = 0; i < n; ++i) {
    if (mp[i].size() == 1 && mp[i].begin()->second == 4) {
      k = i;
      break;
    }
  }
  
  cout << k+1 << '\n';
}

