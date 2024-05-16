#include <iostream>
#include <list>
#include <cmath>
#define ll long long
#define ull unsigned long long
 
void solve(  std::string& s, std::reverse_iterator<std::string::iterator> begin, std::reverse_iterator<std::string::iterator> end, bool first);
 
void change_left_and_right(  std::string& s, std::reverse_iterator<std::string::iterator> left, std::reverse_iterator<std::string::iterator> right)
{
    int n_sequence = 0;
    while (n_sequence < 3)
    {
        std::string temp {*left, *right};
        
        if (temp == "00")
            *right = '1';
        else if (temp == "01")
            *left = '1';
        else if (temp == "11")
            *right = '0';
        else if (temp == "10")
            *left = '0';
 
 
        std::cout << s << '\n';
        ++n_sequence;
    }
}
 
void cycle(std::string& s, std::reverse_iterator<std::string::iterator> leftmost, std::reverse_iterator<std::string::iterator> left, std::reverse_iterator<std::string::iterator> right, bool first = true)
{
    if (first)
    {
        change_left_and_right(s, left, right);
        first = false;
    }
    
 
    *leftmost = (*leftmost == '1') ? '0' : '1';
    std::cout << s << '\n';
    
    change_left_and_right(s, left, right);
    
    solve(s, s.rbegin(), leftmost, false);
      
}
 
 
void solve(  std::string& s, std::reverse_iterator<std::string::iterator> begin, std::reverse_iterator<std::string::iterator> end, bool first = true) 
{
    if (begin == s.rend())
        return;
    
    auto right = s.rbegin();
    auto left = s.rbegin()+1;
    auto leftmost = begin + 2;
 
    while (leftmost != end)
    {
        if (first)
            {
                cycle(s, leftmost, left, right);
                first = false;
            }
        else
            cycle(s, leftmost, left, right, false);
        leftmost++;
    }
}
 
 
int main() {
  
    /*
    0000
    0001
    0011
    0010
    0110
    0100
    0101
    0111
    1111
    1110
    1100
    1101
    1001
    1011
    1010
    1000
 
    000
    001
    011
    010
    100
    101
    111
    110
 
    00000
    00001
    00011
    00010
    00110
    00100
    00101
    00111
    01111
    01110
    01100
    01101
    01001
    01011
    01010
    01000
    11000
    11001
    11011
    11010
    10010
    10000
    10001
    10011
    10111
    10110
    10100
    10101
    */
    
    
    
    std::ios::sync_with_stdio(false);
 
    int n;
    std::cin >> n;
 
    std::string s;
    for ( int i = 0; i < n; ++i )
        s.push_back('0');
 
    std::cout << s << '\n';
    if (n > 2)
    {
        /* auto right = s.rbegin();
        auto left = s.rbegin()+1;
        auto leftmost = s.rbegin()+2; */
        
        solve(s, s.rbegin(), s.rend());
 
        
    }
    else
    {
        if (n == 1)
            std::cout << "1";
        else
            std::cout << "01\n" << "11\n" << "10\n"; 
    }
 
}
