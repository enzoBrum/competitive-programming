#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
 
 
#define fast_io() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define ll long long
#define ull uint64_t
#define sz(x) (int (x.size()))
 
 
 
/*
 
aabd
aadb --> swap --> abda --> sort --> abad
abad
abda
adab
adba
baad
bada
bdaa
daab
daba
dbaa
*/
 
int factorial(int n)
{
    return ( n == 1 ) ? 1 : factorial(n-1) * n;
}
 
 
int permutation_size(const std::string& s)
{
    std::unordered_map<char, int> map;
    
    int fac = factorial(sz(s));
 
    for ( auto ch : s )
    {
        if ( map.contains(ch) )
            map[ch] += 1;
        else
            map[ch] = 1; 
    }
 
    for ( auto item : map )
    {
        int val = item.second;
 
        if (val)
            fac = fac / factorial(val);
    }
    return fac;
    
}
 
 
 
std::string::iterator next_letter(std::string& s, std::string::iterator begin, std::string::iterator end)
{
    if ( !(*begin) )
        return end;
    
    auto begin_copy = begin;
    char current = *begin;
 
    begin++;    
    char tmp = 127;
    auto it = begin;
 
    while (begin != end)
    {
        if ( *begin < tmp && *begin > current )
        {
            tmp = *begin;
            it = begin;
        }
        ++begin;
    }
 
    if ( tmp == 127 )
        return end;
    
    std::swap( *begin_copy, *it );
    std::sort( begin_copy+1, end );
 
    std::cout << s << '\n';
    return begin_copy;
}
 
 
 
void print_str(std::string& s,std::string::iterator begin, std::string::iterator end)
{
    std::swap(*begin, *end);
    std::cout << s << '\n';
    std::swap(*begin, *end);
}
 
void permutate(std::string& s,std::string::iterator begin, std::string::iterator end)
{
    if ( begin == end )
        return;
    
    
    if ( begin + 1 == end - 1  && *begin != *(end - 1) )
    {
        print_str(s, begin, end-1);
        return;        
    }
 
    permutate( s, begin + 1, end );
    begin = next_letter( s, begin, end );
    while ( begin != end )
    {
        permutate( s, begin + 1, end );
        begin = next_letter( s, begin, end );
    }
}
 
 
 
int main() {
    fast_io();
 
    std::string s;
    std::cin >> s;
    
    std::sort(s.begin(), s.end());
    std::cout << permutation_size(s) << '\n' 
              << s << '\n';
    permutate(s, s.begin(), s.end());
       
    
}
