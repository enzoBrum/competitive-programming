#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  if (n == 1) {
    cout << "N\n";
    return 0;
  }

  vector<ll> divisors;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i != 0)
      continue;
    divisors.push_back(i);

    if (i * i != n)
      divisors.push_back(n / i);
  }

  if (divisors.size() == 2) {
    cout << "Y\n";
    return 0;
  }
  divisors.erase(divisors.begin());
  sort(rall(divisors));
  divisors.erase(divisors.begin());

  vector<int> non_relative_prime_paths;

  vector<bool> chosen(divisors.size(), 0);
  int num_chosen = 0;

  while (num_chosen != divisors.size()) {
    ll last = n;
    int path_size = 0;

    ll gcd_result;
    for (int i = 0; i < divisors.size(); ++i)
      if (!chosen[i] && (gcd_result = gcd(divisors[i], last)) != 1)
        path_size++, last = gcd_result, chosen[i] = true, num_chosen++;
    non_relative_prime_paths.push_back(path_size);
  }

  sort(rall(non_relative_prime_paths));

  char ans;
  if (non_relative_prime_paths.size() == 1)
    ans = non_relative_prime_paths[0] % 2 == 0 ? 'Y' : 'N';
  else if (non_relative_prime_paths.size() == 2)
    ans = (non_relative_prime_paths[0] == 1 && non_relative_prime_paths[1] == 1)
              ? 'Y'
              : 'N';
  else
    ans = 'N';
  cout << ans << '\n';
}
