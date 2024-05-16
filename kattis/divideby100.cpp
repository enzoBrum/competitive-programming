#include <iostream>
#include <string>
#include <sys/types.h>
#include <vector>
#include <utility>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <array>
#include <numeric>
#include <bitset>

#define sz(x) (int (x.size()))
#define fast_io() {ios::sync_with_stdio(0); cin.tie(NULL);}

typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pi> vii;
using namespace std;


void insert_zeroes(string& s, int n) {
    string tmp;
    for ( int i = 0; i < n; ++i )
        tmp.push_back('0');
    
    for ( auto& c : s )
        tmp.push_back(c);

    s = tmp;
}

void remove_zeroes(string& s) {
    while (s[sz(s) - 1] == '0') s.pop_back();
}

int main() {
    fast_io();

    string n, m;
    cin >> n >> m;

    int power = sz(m) - 1;
    
    if ( sz(n) >= sz(m) ) {
        int dot_pos = sz(n) - power;
        n.insert( n.begin() + dot_pos, '.' );

    } else {
        insert_zeroes(n, sz(m) - sz(n));
        n.insert(n.begin() + 1, '.');   
    }
    remove_zeroes(n);
    if ( n.back() == '.' ) n.pop_back();

    cout << n << '\n';

}