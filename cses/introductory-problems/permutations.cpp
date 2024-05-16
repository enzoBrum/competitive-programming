#include <iostream>
#define ll long long
 
 
int main() {
    std::ios::sync_with_stdio(false);
 
    int n;
    std::cin >> n;
 
    if (n > 1 and n < 4)
        std::cout << "NO SOLUTION";
 
    else {
        int h_odd = (n % 2 == 0) ? n-1 : n;
        int h_even = (n % 2 != 0) ? n-1 : n;
 
        for (int i = h_odd; i > 0; i-=2)
        {
            std::cout << i << ' ';
        }
 
        for (int i = h_even; i > 0; i-=2)
        {
            std::cout << i << ' ';
        }
    }
}
