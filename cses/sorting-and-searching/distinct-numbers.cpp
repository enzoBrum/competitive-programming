#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <set>
#include <vector>
#define sz(x) (int (x.size()))
#define fast_io() {ios::sync_with_stdio(0); cin.tie(NULL);}
 
typedef long long ll;
typedef uint64_t ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pi> vii;
using namespace std;
 
 
int main() {
  fast_io();
 
 
 
  int n;
  cin >> n;
  vector<int> s;
 
 
  while (n--) {
    int aux;
    cin >> aux;
    s.push_back(aux);
  }
  
  sort(s.begin(),s.end());
  int ans = s.size();
  for ( int i = 0; i < s.size()-1; ++i ) {
    if (s[i] == s[i+1])
      ans--;
  }
  cout << ans;
}
