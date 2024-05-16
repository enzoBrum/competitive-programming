#include <iostream>
#define ll long long
 
int main() {
    std::ios::sync_with_stdio(false);
 
    /*
    
    x - x_0 = 2     x - x_0 = 1
    y - y_0 = 1     y - y_0 = 2
    
    
    1 + 2 + 2 + 1
    
    1+2x = y
    x = (y-1)/2
 
    2+2x = y
    */
 
   int num;
   std::cin >> num;
 
    for (int n = 1; n < num+1; ++n) {
        int last_even = (n % 2 == 0) ? n : n-1;
        int last_odd = (n % 2 != 0) ? n : n-1;
        int pairs = (last_odd-1)/2 + (last_even-2)/2;
 
 
        int attack_moves = 2*pairs*( 1 + 2 * (n-2) +  1  );
 
        ll n_square = n*n;
        ll max_moves = (n_square*(n_square-1))/2;
 
        std::cout << max_moves - attack_moves << '\n';
    }
}
