#include <algorithm>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <iterator>
#include <random>
#include <set>
#include <map>
#include <sstream>
#include <string>
#include <unordered_set>
#include<iostream>
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
 
int main() {
    fast_io();
    
    int n, x;
    cin >> n >> x;
    
    vii vec(n);
    for (int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        vec[i] = {tmp, i+1};
    }
    
    sort(vec.begin(), vec.end(), [](const pi& a, const pi& b){return a.first < b.first;});
    
    for (int i = 0; i < vec.size(); ++i) {
    	int a = vec[i].first;
    	
    	int l = 0;
    	int r = i-1;
    	
    	while ( l < r ) {
    		int sum = vec[i].first + vec[l].first + vec[r].first;
    		if ( sum == x ) {
    			cout <<  vec[i].second << ' ' << vec[l].second << ' ' << vec[r].second << '\n';
    			return 0;
    		}
    		
    		if ( sum < x ) l++;
    		else r--;
    	}
    	
    }
    cout << "IMPOSSIBLE\n";
}
