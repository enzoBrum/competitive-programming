#include <iostream>
#include <cmath>
#define ll long long
#define ull unsigned long long
 
int main() {
   
    std::ios::sync_with_stdio(false);
 
    int n;
    std::cin >> n;
 
    int ans =  0;
    int num = 1;
 
    while (num < n)
    {
        num *= 5;
        ans += n / num;
    }
 
    std::cout << ans;
}
