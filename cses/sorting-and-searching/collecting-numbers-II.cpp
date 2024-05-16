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
 
 
 
void update(vi& vec, vi& vec2, int a, int b, int va, int& ans) {
  if ( vec2[va - 1] <= vec2[va] && vec2[va - 1] > b ) ans++;
  else if ( vec2[va - 1] > vec2[va] && vec2[va - 1] <= b ) ans--;
 
  if ( vec2[va] <= vec2[va+1] && b > vec2[va+1] ) ans++;
  else if ( vec2[va] > vec2[va+1] && b <= vec2[va+1] ) ans--;
 
  vec2[va] = b;
}
 
 
int main() {
  fast_io();
  int n, m;
 
  cin >> n >> m;
  vi vec(n), vec2(n+1);
  for (int i = 0; i < n; ++i) {
    int aux;
    cin >> aux;
    
    vec[i] = aux - 1;
    vec2[aux - 1] = i;
  }
 
  int ans = 0;
  for ( int i = 1; i < sz(vec2); ++i ) {
    if ( vec2[i-1] >= vec2[i] ) ans++;
  }
 
  vec2[n] = n; 
  while (m--) {
    int a, b, va, vb;
    cin >> a >> b;
 
    a--; b--;
    va = vec[a];
    vb = vec[b];
 
    swap(vec[a], vec[b]);
 
    update(vec, vec2, a, b, va, ans);
    update(vec, vec2, b,a, vb, ans);
 
    cout << ans << '\n';
  }
 
 
}
