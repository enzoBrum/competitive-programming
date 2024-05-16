#include <iostream>
#include <vector>
#include <numeric>
#define ll long long
 
// string array!!
 
/*
 
n is odd
1,2, 4, n, 6, n-2, ...
3, 5, n-1, 7, n-3,...
 
n is even
1,n,3,n-2,...
2,n-1, 4, n-3,...
 
 
 
 
1,2
3
 
1,2,4,7
3,5,6
 
1,2, 4, 7
3, 5, 6
 
1,2,4,6
3, 5
 
 
1,8,3,6
2,7,4,5
 
1,2, 4,6
3, 5
 
1,6,3,4
2,5
 
 
 
*/
 
int main() {
    std::ios::sync_with_stdio(false);
 
    int n;
    std::cin >> n;
 
    std::vector<int> vec(n);
    std::iota(vec.begin(), vec.end(), 1);
 
    std::string a,b;
    std::vector<int>::iterator begin = vec.begin();
    std::vector<int>::iterator end = vec.end() - 1;
    
 
    bool n_is_even = n % 2 == 0;
    if ( (n_is_even && n / 2 % 2 != 0) || ( !n_is_even && (n-3) / 2 % 2 != 0 ) )
        std::cout << "NO";
 
    else {
        if (n_is_even)
        {
            while ( begin < end) {
                std::string aux = std::to_string(*begin) + ' ' + std::to_string(*end) + ' ';
                a.append(aux);
                
                ++begin;
                --end;
 
                aux = std::to_string(*begin) + ' ' + std::to_string(*end) + ' ';
                b.append(aux);
 
                ++begin;
                --end;
            }
        }
 
        else 
        {
            a = a + std::to_string(*begin) + ' ' + std::to_string(*(begin+1)) + ' ';
            b = b + std::to_string(*(begin+2)) + ' ';
 
            begin += 3;
 
            while (begin < end)
            {
                std::string aux = std::to_string(*begin) + ' ' + std::to_string(*end) + ' ';
                a.append(aux);
                
                ++begin;
                --end;
 
                aux = std::to_string(*begin) + ' ' + std::to_string(*end) + ' ';
                b.append(aux);
 
                ++begin;
                --end;
            }
 
        }
 
        int a_size = n_is_even ? n / 2 : (n-3) / 2 + 2;
        int b_size = n_is_even ? n / 2 : (n-3) / 2 + 1;
 
        std::cout << "YES\n" << a_size << '\n'
                  << a << '\n' << b_size << '\n'
                  << b;
    }
}
