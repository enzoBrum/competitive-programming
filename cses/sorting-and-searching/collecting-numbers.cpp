#include <algorithm>
#include <bits/ranges_algo.h>
#include <bits/stdc++.h>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <iterator>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
#define sz(x) (int(x.size()))
#define fast_io()                                                              \
  {                                                                            \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(NULL);                                                             \
  }
#define rgsort(x)                                                              \
  { ranges::sort(x); }
 
typedef long long ll;
typedef uint64_t ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pi> vii;
using namespace std;
 
/*
 *std::set<>::extract()
 *ordena o set com base no último elemento do rounds
 *armazena um par valor/posicao
 *cria um vetor com a posicao de cada elemento
 * */
 
 
int main() {
  int n;
 
  cin >> n;
  vi vec(n), vec2(n);
  for (int i = 0; i < n; ++i) {
    int aux;
    cin >> aux;
    
    vec2[aux - 1] = i;
  }
 
  int ans = 1;
  for ( int i = 1; i < sz(vec2); ++i ) {
    if ( vec2[i-1] >= vec2[i] ) ans++;
  }
 
  cout << ans << '\n';
 
 
}
