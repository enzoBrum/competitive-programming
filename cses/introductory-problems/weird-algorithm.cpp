#include <iostream>
#define ll long long
 
 
int main() {
    std::ios::sync_with_stdio(false);
 
    ll n;
    std::cin >> n;
    while (n != 1) {
        std::cout << n << " ";
        
        if (n % 2 == 0) 
            n /= 2;
        else
            n = n*3 + 1;
    }
 
    std::cout << n;
}
