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
 
  int n,m,k;
  cin >> n >> m >> k;
 
  vector<int> applicant, apartment;
  while (n--) {
    int temp;
    cin >> temp;
    applicant.emplace_back(temp);
  }
  while (m--) {
    int temp;
    cin >> temp;
    apartment.push_back(temp);
  }
 
  sort(apartment.begin(), apartment.end());
  sort(applicant.begin(), applicant.end());
 
  auto apartment_it = apartment.begin();
  int ans = 0;
  bool end = false;
  for ( auto& sz : applicant ) {
    if (apartment_it == apartment.end() || end) break;
 
    if ( sz-k > *apartment_it ) {
      while ( sz-k > *apartment_it && !end) {
        if ( apartment_it == apartment.end() ) end = true;
 
        else
          apartment_it++;
      }
    }
 
    if ( sz + k < *apartment_it  ) {
      continue;
    }
 
    if ( abs(sz - *apartment_it) <= k ) {
      ans++;
      apartment_it++;
    }
  }
 
  cout << ans;
}
