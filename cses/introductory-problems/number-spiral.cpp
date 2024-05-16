#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
 
 
int main() {
    std::ios::sync_with_stdio(false);
 
    int t;
    std::cin >> t;
    while (t--) {
        ll y,x;
        std::cin >> y >> x;
 
        ll max = std::max(x,y);
 
        ll val = (2 + 2*(max - 1) )*(max-1)/2 + 1;
 
        ll ans;
        if (x == y)
            ans = val;
        else
        {
            ll diff = abs(x-y);
            int multiplier = (max % 2 == 0) ? -1 : 1;
 
            ans = (max == x) ? val + diff*multiplier : val - diff*multiplier; 
        }
 
        std::cout << ans << ' ';
 
    }
}
