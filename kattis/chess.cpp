#include <bits/stdc++.h>
#define sz(x) (int (x.size()))

typedef long long ll;
typedef uint64_t ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
using namespace std;

/*
00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33

x+y
y-x+n-1

*/

// 'A' -> 65
// tem que converter o número


pair<char, int> convert_output(pi data)
{
    return make_pair(
        (char) (data.first + 65),
        8 - data.second
    );
}
pi convert_input( char a, int b )
{
    return make_pair(
        (int) a - 65,
        8-b
    );
}



string pos_to_str(int x, int y)
{
    string s;
    char a = x+48;
    char b = y+65;
    s.push_back(a);
    s.push_back(b);
    return s;
}

bool is_valid(pi p)
{
    return 0 <= p.first && p.first <= 7  && p.second >= 0 &&  p.second <= 7;
}

void solve(pi a, pi b)
{
    int bd = b.first + b.second;    
    int bd2 = b.first - b.second + 7;

    auto a1 = a;
    auto a2 = a;            
    
    bool d1 = false, d2 = false;
    while ( true ) {
        if ( !is_valid(a1) && !is_valid(a2) )
                break;
        
        else if ( is_valid(a1) && a1.first + a1.second == bd )
        {
            d1 = true;
            break;
        }

        else if (is_valid(a2) && a2.first - a2.second + 7 == bd2)
        {
            d2 = true;
            break;
        }

        a1.first--; a1.second--;
        a2.first--; a2.second++;

    }
    if (!d1 && !d2)
    {
        a1 = a;
        a2 = a;
        while ( true ) {
            if ( !is_valid(a1) && !is_valid(a2) )
                break;
            
            else if ( is_valid(a1) && a1.first + a1.second == bd )
            {
                d1 = true;
                break;
            }

            else if (is_valid(a2) && a2.first - a2.second + 7 == bd2)
            {
                d2 = true;
                break;
            }

            a1.first++; a1.second++;
            a2.first++; a2.second--;
            
    }   
    }

    pair<char, int> dest = convert_output(b);
    pair<char,int> mv;

    if (d1)
        mv = convert_output(a1);
    else
        mv = convert_output(a2);

    auto og = convert_output(a);

    if ( og.first == mv.first && og.second == mv.second )
        cout << "1 " << og.first << ' ' << og.second <<
            ' ' << dest.first << ' ' << dest.second << '\n';

    else
        cout << "2 " << og.first << ' ' << og.second <<
            ' '<< mv.first << ' ' << mv.second << ' ' <<
            dest.first << ' ' << dest.second << '\n';
            
}


int main() {
    // fast_io();
    
    int n;
    cin >> n;
    while (n--)
    {
        char x1, x2;
        int y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        pi a = convert_input(x1,y1);
        pi b = convert_input(x2,y2);

        if ( ((a.first+a.second)&1) != ((b.first+b.second)&1) )
            cout << "Impossible\n";
        else
        {
            if (x1 == x2 && y1 == y2)
                {
                    cout << "0 ";
                    cout << x1 << ' ' << y1 << '\n';
                }
            else
                {
                    solve(a,b);
                }
        }
    }
}

