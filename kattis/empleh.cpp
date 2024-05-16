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

enum class Color {
    WHITE, 
    BLACK
};

struct Piece {
    char type;
    pi pos;

    Piece(char t, pi p, Color col)
        :pos{p} {
            if (col == Color::WHITE) 
                type = toupper(t);
            else
                type = tolower(t);
        }
    
};

pi convert_pos(char x, char y) {
    return make_pair(
        (int) x - 97,
        8 - ((int) y - 48)
    );
}


vector<Piece> split(const string& s, char c, Color col) {
    int pos = 0; string piece; vector<Piece> vec;
    while (pos != sz(s)) {
        auto lim = s.find(c, pos);
        if ( lim == string::npos )
            piece = s.substr(pos, sz(s)- pos);
        else
            piece = s.substr(pos, lim-pos);
        
        pos = lim+1;
        
        if (sz(piece) == 2)
            piece.insert(piece.begin(), 'p');

        pi piece_position = convert_pos(piece[1], piece[2]);
        char type = piece[0];
        vec.emplace_back(type, piece_position, col);

        if ( lim == string::npos )
            break;
        
    }
    return vec;
}

int main() {
    string s;
    cin.ignore(7);
    getline(cin, s);
    auto white = split(s, ',', Color::WHITE);
    
    cin.ignore(7);
    getline(cin, s);
    auto black = split(s, ',', Color::BLACK);

    bool wh = true;
    string separator = "+---+---+---+---+---+---+---+---+";
    cout << separator << '\n';

    for ( int i = 0; i < 8; ++i )
    {
        for (int j = 0; j <  8; ++j)
        {
            if (j == 0)
                cout << '|';

            char sep = (wh) ? '.' : ':';
            

            auto it = find_if(white.begin(), white.end(), [i,j](const Piece& val) {
                return val.pos.first == j && val.pos.second == i;
            });
            auto it2 = find_if(black.begin(), black.end(), [i,j](const Piece& val) {
                return val.pos.first == j && val.pos.second == i;
            });



            char t;
            if (it != white.end() )
                t = it->type;
            else if (it2 != black.end())
                t = it2->type;
            else
                t = sep;

            cout << sep << t << sep << '|';
            wh = !wh;
        }
        wh = !wh;

        cout << '\n' << separator << '\n';
    }
}