#include <iostream>
#include <list>
#include <cmath>
#define ll long long
#define ull unsigned long long
 
int main() {
  
    std::ios::sync_with_stdio(false);
 
    std::string s;
    std::cin >> s;
 
    std::list<char> list (s.begin(), s.end());
    std::string first, second;
 
    auto it = list.begin();
    int pos = 0;
    bool solution = true;
 
    char middle = '\0';
    bool even = list.size() % 2 == 0;
    while ( it != list.end() && solution)
    {
        first.push_back(*it);
        
        auto iterator = it;
        ++iterator;
 
        while (iterator != list.end())
        {
            if (*iterator == *it)
            {
                second.push_back(*iterator);
                list.erase(iterator);
                break;
            }
 
            ++iterator;
        }
 
 
        if (iterator == list.end() )
        {
            if (!even && !middle)
                {
                    first.pop_back();
                    middle = *it;
                }
            else
            {
                solution = false;
                break;
            }
        }
 
        ++it;
        ++pos;
    }
 
    if (solution || (list.size() > 0 && list.size() < 3) )
        {
            if (middle)
                first.push_back(middle);
            first.append(second.rbegin(), second.rend());
            std::cout << first;
        }
    else
        std::cout << "NO SOLUTION";
    
 
}
