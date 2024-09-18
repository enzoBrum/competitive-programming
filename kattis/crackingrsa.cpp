#include <vector>
#include <numeric>
#include<utility>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<queue>
#include<functional>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<stack>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;
using ull = unsigned  long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  
  vector<int> primes;
  vector<char> is_prime(1001, true);
  
  for (int i = 2; i < 1001; ++i)
    if (is_prime[i])
      for (int j = i+i; j < 1001; j += i)
        is_prime[j] = false;
  
  for (int i = 2; i < 1001; ++i)
    if (is_prime[i])
      primes.push_back(i);
  
  while (t--) {
    ll n, e;
    cin >> n >> e;
    
    int p = -1, q = -1;
    for (int i = 0; i < primes.size(); ++i)
      if (n % primes[i] == 0)
        if (p == -1)
          p = primes[i];
        else
          q = primes[i];
    
    ll totient = (p-1)*(q-1);
    
    // de - 1 = kc
    // de = kc + 1
    // d = (kc + 1)/e;
    
    // d = (k*20 + 1)/3;
    
    // always has a solution.
    ll k = 1;
    while ((k*totient + 1) % e != 0)
      k++;
    
    ll d = (k*totient + 1)/e;
    cout << d << '\n'; 
  }
}

