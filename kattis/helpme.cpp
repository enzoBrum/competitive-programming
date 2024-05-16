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






string convert_pos(int x, int y)
{
    string s;
    
    char letter = x+96;
    string number = to_string((8-y));
    s.push_back(letter);
    s.append(number);
    return s;
}

struct Piece {
    char type;
    string pos;

    Piece(char t, string p)
        :type{t}, pos{p} {}
    
    string toString()
    {
        if (type == 'P')
            return pos;
        return string(1,type) + pos;
    }
};

int i = 0, j = 0;
int main() {
    vector<Piece> white, black;

    string s;
    int x = 0, y = 0;
    getline(cin, s);

    while ( getline(cin, s) ) 
    {
        for ( int i = 0; i < sz(s); ++i )
        {
            cin.ignore(1); 
            switch (s[i]) {
                case '|':
                    x++;
                    break;
                case ':':
                case '.': 
                    break;
                default:
                {
                    char c = s[i];
                    
                    if ( (int) c < 97 )
                        white.push_back(Piece(
                            (char) toupper(c),
                            convert_pos(x,y)
                        ));
                    else   
                        black.push_back(Piece(
                            (char) toupper(c),
                            convert_pos(x,y)
                        ));
                }
            }
        }
        getline(cin, s);
        x = 0;
        ++y;
    }

    unordered_map<char, int> val = {
        {'K', 0}, {'Q', 1}, {'R', 2}, {'B', 3},
        {'N', 4}, {'P', 5}
    };
    sort(white.begin(), white.end(), [&val](const Piece& a, const Piece& b){
        if ( val[a.type] == val[b.type]  )
        {
            if (a.pos[1] == b.pos[1])
                return a.pos[0] < b.pos[0];
            return a.pos[1] < b.pos[1];
        }
         
        return val[a.type] < val[b.type];
    });
    
    sort(black.begin(), black.end(), [&val](const Piece& a, const Piece& b){
        if ( val[a.type] == val[b.type]  )
        {
            if (a.pos[1] == b.pos[1])
                return a.pos[0] < b.pos[0];
            return a.pos[1] > b.pos[1];
        }
        return val[a.type] < val[b.type];
    });


    cout << "White: ";
    for ( auto it = white.begin(); it < white.end(); ++it )
    {
        if ( it == white.end()-1 )
            cout << (*it).toString();
        else
            cout << (*it).toString() << ',';
    }
    cout << "\nBlack: ";
    for ( auto it = black.begin(); it < black.end(); ++it )
    {
        if ( it == black.end()-1 )
            cout << (*it).toString();
        else
            cout << (*it).toString() << ',';
    }

}

