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

  ll n; cin >> n;
  vector<ll> vec(n);
  for (auto& v : vec) cin >> v;
  

  unordered_map<ll, ll> mp_sum;
  ll curr = 0;

  ll ans = 0;
  for (auto& v : vec) {
    // ll mod = (v + curr) % n;
    ll mod = (n + ((v + curr) % n)) % n;
    
    if (!mod) ans++;
    if (mp_sum.count(mod)) ans += mp_sum[mod];
    mp_sum[mod]++;
    curr += v;
  }

  cout << ans << '\n';
}
/*
y - x = n
(y-x) mod n = n mod n
y mod n - x mod n = 0
y mod n = x mod n

5
-60
-127

-127 + 60 = -67
*/
