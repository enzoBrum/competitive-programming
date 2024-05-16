#include <map>
#include <queue>
#include <cmath>
#include<iostream>
#include <string>
#include <unordered_map>
#include<vector>
#include<algorithm>
#include<sstream>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ll n, k;
  cin >> n >> k;
  vector<ll> vec(n);
  for (auto& v : vec) cin >> v;

  ll ans = 0;

  map<ll, ll> mp;
  ll begin = 0;
  for (ll i = 0; i < n; ++i) {
    while ((mp.size() > k || (mp.size() == k && !mp.count(vec[i])) )&& begin < vec.size()) {
      ll num = vec[begin++];
      mp[num]--;

      if (!mp[num]) mp.erase(num);
    }
    
    mp[vec[i]]++;
    ans += i - begin + 1;
  }

  cout << ans << '\n';
}

