#include <iostream>
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
    fast_io();
    int n;
    cin >> n;

    int last = 0;
    vi vec;

    while (n--) {
        int tmp;
        cin >> tmp;

        if ( tmp > last ) {
            vec.push_back(tmp);
            last = tmp;
        }
    }

    cout << sz(vec) << '\n';
    for_each(vec.begin(), vec.end(), [](const int& i) {cout << i << ' ';});
}