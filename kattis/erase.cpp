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

bool validate(string bf, string af, int n) {
	bool ret = true;
	
	if (n % 2 == 0 && bf != af)
	    ret = false;
	
	else if ( n % 2 != 0 ) {
		for (int i = 0; i < sz(bf); i++) {
			char cbf = (bf[i] == '1') ? '0' : '1';
			
			if ( cbf != af[i] ) {
				ret = false;
				break;
			}
		}
	}
	
	return ret;
}
  
int main() {
	int n;
	fast_io();
	string bf, af;
	cin >> n >> bf >> af;
	
	if (validate(bf, af, n)) 
	    cout << "Deletion succeeded\n";
	else
	    cout << "Deletion failed\n";
	
	return 0;
}
