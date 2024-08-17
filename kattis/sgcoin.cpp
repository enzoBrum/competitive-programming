#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

const int mod = 1e9 + 7;

pair<ll, ll> H(long long previousHash, const string &transaction) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  
  /*
  (v * 7 + token) % (1e9 + 7)
  ((v * 7) % (1e9 + 7) + token % (1e9 + 7)) % (1e9 + 7)
  */

  v = (v*7) % mod;
  
  ll token;
  if (v < 990000000) {
    token = 990000000 - v;
  } else {
    token = 110000000 + ( 1000000007 - v );
  }

  return {(v + token) % mod, token};
}
long long H(long long previousHash, const string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  ll n; cin >> n;
  
  auto[curr_hash, token] = H(n, "hello-world");
  cout << "hello-world " << token << '\n';

  auto[bhash, btoken] = H(curr_hash, "hello-world");
  cout << "hello-world " << btoken << '\n';
}
