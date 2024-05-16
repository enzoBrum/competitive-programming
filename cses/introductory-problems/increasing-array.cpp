#include <iostream>
#define ll long long
 
 
int main() {
    std::ios::sync_with_stdio(false);
 
 
    int n;
    std::cin >> n;
 
    ll last {0}, sum {0};
    for (int i = 0; i < n; ++i) {
        ll current;
        std::cin >> current;
 
        if (current < last)
            sum = sum - current + last;
        else
            last = current;
    }
 
    std::cout << sum;
 
}
