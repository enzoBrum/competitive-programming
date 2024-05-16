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
 
 
bool valid(ull time, ull goal,vull& machines) {
  ull sum = 0;
  for (auto& m : machines) 
    sum += time/m;
 
  return sum >= goal;
}
 
 
int main() {
  fast_io();
 
  ull n, t;
  cin >> n >> t;
 
  vull machines;
  while (n--) {
    ull tmp;
    cin >> tmp;
    machines.push_back(tmp);
  }
 
  
  ull boundary = t*(*max_element(machines.begin(), machines.end())) + 1;
  DEBUG(boundary);
  ull k = 0;
  for (ull b = boundary/2; b >= 1; b /= 2) {
    DEBUG(valid(k+b, t,machines));
    while (!valid(k+b, t,machines)) k+=b;
  }
 
  cout << k+1 << '\n';
 
 
}
