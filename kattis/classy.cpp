#include<cmath>
#include <sstream>
#include<cstdint>
#include<iterator>
#include <string>
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
typedef std::vector<std::string> vs;
typedef std::vector<std::vector<std::string>> vvs;
typedef std::vector<char> vc;
typedef std::vector<std::vector<char>> vvc;
typedef std::vector<std::vector<std::string>> vvs;
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


unordered_map<string, int> classes = {
  {"lower",0}, {"middle",1}, {"upper",2}
};

bool cmp(pair<string,string>& pa, pair<string,string>& pb) {
  string& a = pa.first;
  string& b = pb.first;
  
  if (a == b) return pa.second < pb.second;
  stringstream sa(a), sb(b);


  string buf_a, buf_b;
  while (getline(sa, buf_a, '-') && getline(sb, buf_b, '-')) {
    if (buf_a == buf_b) continue;
    return classes[buf_a] > classes[buf_b];
  }
  // return true;
}

int main() {
  fast_io();
  int t; cin >> t;

  while(t--) {
    int n; cin >> n;

    vector<pair<string, string>> vec;
    while (n--) {
      string name, cls, _;
      cin >> name >> cls >> _;
      name.pop_back();

      vector<string> aux;
      stringstream ss;
      ss << cls;
      string buffer;
      while (getline(ss, buffer, '-'))
        aux.push_back(buffer);

      int num_middle = 10 - aux.size();
      string cls_with_padding;

      for (auto it = aux.rbegin(); it != aux.rend(); ++it)
        cls_with_padding += *it + "-";

      while (num_middle--)
        cls_with_padding += "middle-";
      cls_with_padding.pop_back();

      vec.emplace_back(cls_with_padding, name);
    }

    sort(vec.begin(), vec.end(), cmp);
    for (auto&[_,name] : vec) cout << name << '\n';
    cout << "==============================\n";
  }
}