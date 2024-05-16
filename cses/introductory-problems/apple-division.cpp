#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <unordered_map>
 
typedef long long ll;
typedef uint64_t ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
 
#define sz(x) (int (x.size()))
#define fast_io() std::ios::sync_with_stdio(0); std::cin.tie(0);
 
vll vec, a;
ll min = INT64_MAX;
 
vll find_complement()
{
    vll temp = vec;
 
    for ( auto n : a )
    {
        auto it = std::find( temp.begin(), temp.end(), n );
        if ( it != temp.end() )
            temp.erase(it);
    }
    return temp;
}
 
 
void subset(int i)
{
    if (i == sz(vec) )
        return;   
    else {
        auto b = find_complement();
        ll val_a = std::accumulate( a.begin(), a.end(), 0ll );
        ll val_b = std::accumulate( b.begin(), b.end(), 0ll );
        ll diff = ( val_a > val_b ) ? val_a-val_b : val_b-val_a;
        min = std::min(min, diff);
 
        a.push_back(vec[i]);
        subset(i+1);
        a.pop_back();
        subset(i+1);
    }
    
}
 
 
 
 
int main() {
    fast_io();
 
    int n;
    std::cin >> n;
    
    while (n--)
    {
        ll v;
        std::cin >> v;
        vec.push_back(v);
    }
    std::sort(vec.begin(), vec.end(),  []( ll a, ll b ) { return a >= b; } );    
    subset(0);
    std::cout << min;
}
