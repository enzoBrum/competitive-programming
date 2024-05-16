#include <iostream>
#include <cmath>
 
#define ll long long
#define ull uint64_t
 
void print_move(int start, int end)
{
    std::cout << start << ' ' << end << '\n';
}
 
 
void mv(int n, int start, int end)
{
    if (n == 1)
    {
        print_move(start, end);
        return;
    }
 
    int mid = 6 - start - end;
    mv(n-1, start, mid);
    mv(1, start, end);
    mv(n-1, mid, end);
}
 
 
int main() {
    std::ios::sync_with_stdio(0);
    
    int n;
    std::cin >> n;
    std::cout << (ll) pow(2, n) - 1 << '\n';
    mv(n, 1, 3);
}
