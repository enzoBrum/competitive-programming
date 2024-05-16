#include<cmath>
#include <sstream>
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

// #ifdef DB
//   #define DEBUG(s) std::cout << s << '\n';
// #else
//   #define DEBUG(s);
// #endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
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


int main() {
    fast_io();
    string question;
    getline(cin, question);

    int n;
    cin >> n;

    array<array<string, 100>, 100> arr;
    vector<pair<int, string>> ans;

    cin.ignore(256, '\n');
    for (int i = 0; i < n; ++i) {
      string line;
      getline(cin, line);
      ans.emplace_back(0, line);

      stringstream ss{line};
      string buffer;
      int j = 0;
      while (getline(ss, buffer, ',')) {
        arr[i][j] = buffer;
        j++;
      }
    }
    
    for (int k = 0; k < n; ++k) {
      for (int i = k; i < n; ++i) {
        int curr = 0;
        for (int j = 0; j < 100; ++j) {
          if (arr[i][j] != arr[k][j]) curr++;
        }
        ans[i].first = max(ans[i].first, curr);
        ans[k].first = max(ans[k].first, curr);
      }
    }
    
    stable_sort(ans.begin(), ans.end(), [](const pair<int, string>& a, const pair<int, string>& b) {return a.first < b.first;});
    cout << ans[0].second << '\n';
    for (int i = 1; i < ans.size(); ++i) {
      if (ans[i].first == ans[i-1].first)
        cout << ans[i].second << '\n';
      else
        break;
    }
}

