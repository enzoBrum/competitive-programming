#include <iostream>
#define ll long long
 
 
int main() {
    std::ios::sync_with_stdio(false);
 
 
    ll sum = 0;
    ll n;
    std::cin >> n;
    for (int i = 0; i < n-1; ++i) {
        ll m;
        std::cin >> m;
        sum += m;
    }
 
    std::cout << ((1+n)*n)/2 - sum;
 
}
