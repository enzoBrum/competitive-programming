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
#include <map>
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
 
 
int main() {
	  fast_io();
	   
	    int n;
	      int ans = 0, curr = 0;
	       
	        cin >> n;
		 
		  map<int, int> mp, mp2;
		    vi vec;
		      while (n--) {
			          int tmp;
				      cin >> tmp;
				          vec.push_back(tmp);
					    }
		       
		        for (int i = 0; i < vec.size(); ++i) {
				    if ( mp.contains(vec[i]) ) { 
					          int index = mp[vec[i]];
									        ans = max((int)mp.size(), ans);
						        for (auto& ii : mp2) {
									      if (ii.first == index) break;
									      	      mp.erase(ii.second);
										            }
							      
							      mp2.erase(mp2.begin(), ++mp2.find(index) );
							            
							            mp2[i] = vec[i];
								          
										      mp[vec[i]] = i;
										          }
				        else {
						            pi p = { vec[i], i };
							          pi pp = { i, vec[i] };
								        mp.insert(p);
									      mp2.insert(pp);
									          }
					 
					  }
			ans = max(ans, (int) mp.size() );
			    cout << ans << '\n';
}
