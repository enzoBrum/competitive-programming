#include <iostream>
#include <cmath>
#define ll long long
#define ull unsigned long long
 
int main() {
    /*
    a*b = c
    a mod d * b mod d  mod d= a*b mod d = c mod d
 
    a*b*c = d
    ((a mod e * b mod e) mod e) * 
    
    2**64 % 10**9
    2**63*2 % 10**9
    (2**63 % 10**9) * 2 % 10**9
    
    
    n = 129
    2**129 % 10**9 + 7
    (((2**64) % 10**9) * (2**64) % 10**9) % 10**9 + 7
    */
    
    
    std::ios::sync_with_stdio(false);
 
    int n;
    std::cin >> n;
    
    int ten_nine = pow(10,9) + 7;
    ull max = pow(2, 63);
    ull max_mod = max % ten_nine;
    int n_of_63 = n / 63;
    int n_of_2 = n % 63;
 
    ll val_63  = 1;
    int temp = n_of_63;
    while (temp > 0) {
        val_63 = (val_63 % ten_nine * max_mod) % ten_nine;
        --temp;
    }
 
    if (n_of_63 > 0)
    {
        std::cout << (val_63 * ( (ull) pow(2,n_of_2) % ten_nine )) % ten_nine;
    }
        
    else
        std::cout << (ull) pow(2,n_of_2) % ten_nine;
 
 
}
