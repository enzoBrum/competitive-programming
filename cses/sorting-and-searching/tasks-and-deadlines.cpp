#include<cstdint>
#include<iterator>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<functional>
 
#define sz(x) (int (x.size()))
#define fast_io() {ios::sync_with_stdio(0); cin.tie(NULL);}
#define mult_vec(name,T,n,m) std::vector<std::vector<T>>name(n, std::vector<T>(m))
// #define DB 
 
#ifdef DB
  #define DEBUG(s) std::cout << s << '\n';
#else
  #define DEBUG(s);
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pi> vpi;
typedef std::vector<pll> vpll;
typedef std::vector<pull> vpull;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<ll>> vvll;
typedef std::vector<std::vector<ull>> vvull;
typedef std::vector<std::vector<pi>> vvpii;
typedef std::vector<std::vector<pll>> vvpll;
typedef std::vector<std::vector<pull>> vvpull;
 
using namespace std;
 
 
int main() {
  fast_io();
 
  int n;
  cin >> n;
  vpll tasks;
 
  while (n--) {
    int a, d;
    cin >> a >> d;
    tasks.emplace_back(a, d);
  }
 
  sort(tasks.begin(), tasks.end());
 
  ll time = 0;
  ll ans = 0;
 
  for (auto&[duration, deadline] : tasks) {
    ans += (deadline - (time+duration));
    time += duration;
  }
 
  cout << ans << '\n';
 
}
