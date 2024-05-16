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


int main() {
    int n;
    string code, guess;
    cin >> n >> code >> guess;

    vector<char> guess_colors;
    unordered_multiset<char> code_colors;
    for ( auto& c : code ) code_colors.insert(c);

    int r = 0, s = 0;
    for ( int i = 0; i < sz(code); ++i ) {
        if ( guess[i] == code[i] ) {
            r++;
            code_colors.erase(code_colors.find(guess[i]));
        }
    }
    for (int i = 0; i < sz(code); ++i) {
        if ( guess[i] != code[i] && code_colors.count(guess[i]) ) {
            s++;
            code_colors.erase(code_colors.find(guess[i]));
        }
        
    }

    cout << r << ' ' << s << '\n';
}