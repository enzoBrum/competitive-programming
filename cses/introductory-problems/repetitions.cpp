#include <iostream>
#define ll long long
 
 
int main() {
    std::ios::sync_with_stdio(false);
 
 
    int longest = 1;
    int current = 0;
 
    std::string seq;
    std::cin >> seq;
 
    char last = ' ';
    for ( auto ch : seq ) {
        current++;
        
        if (last != ch) {
            current = 1;
            last = ch;
            continue;
        }
 
        
        else if (current > longest) {
            longest = current;
        }
    }
 
    std::cout << longest;
 
}
