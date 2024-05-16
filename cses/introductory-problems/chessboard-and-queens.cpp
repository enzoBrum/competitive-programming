#include <iostream>
#include <algorithm>
#include <array>
#include<vector>
 
typedef long long ll;
typedef uint64_t ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
 
#define sz(x) (int (x.size()))
#define fast_io() std::ios::sync_with_stdio(0); std::cin.tie(0);
 
 
std::array<std::array<char, 8>, 8> arr;
//std::array<std::array<bool, 8>, 8> cols;
std::array<bool, 8> col;
std::array<bool, 15> diag, diag2;
 
int n = 0;
 
 
 
 
void solve(int k) {
    if ( k == arr.size() )
    {
        n++;
        return;
    }
    else {
        // diag --> i+j
        // diag2 --> j-i+arr.size()-1
            int i = k;        
 
            for ( int j = 0; j < sz(arr); ++j ) 
            {
                if ( arr[i][j] == '*' || col[j] || diag[i+j] || diag2[j-i+sz(arr)-1]  )
                    continue;
 
                col[j] = diag[i+j] = diag2[j-i+sz(arr)-1] = true;
                solve( k+1 );
                col[j] = diag[i+j] = diag2[j-i+sz(arr)-1] = false;
            }
 
    }
}
 
int main() {
    fast_io();
    
    for ( int i = 0; i < 8; ++i )
        for ( int j = 0; j < 8; ++j )
            std::cin >> arr[i][j];
    
    solve(0);
    std::cout << n;
}
