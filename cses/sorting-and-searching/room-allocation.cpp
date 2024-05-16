#include<queue>
#include<stack>
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
 
  vector<array<int, 3>> customers, vec;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
 
    vec.push_back({a, 0, i});
    vec.push_back({ b, 1, i });
    customers.push_back({a,b,0});
  }
  
  sort(vec.begin(), vec.end());
 
  
  vector<bool> rooms;
  map<int, vi> mp;
  queue<int> free;
  int num = 1;
  priority_queue<pi, vpi, greater<pi>> pq;
  for (auto&[day, action, index] : vec) {
    if (action) {
      auto[_, room] = pq.top();
      free.push(room);
      pq.pop();
    } 
    else {
      int exit_day = customers[index][1];
      int room;
      if (free.empty())
        room = num++;
      else {
        room = free.front();
        free.pop();
      }
 
      pq.push({exit_day, room});
      
      customers[index][2] = room;
      }
    }
  
  cout << num-1 << '\n';
  for (auto&[a, b, r] : customers)
    cout << r << ' ';
  
}
