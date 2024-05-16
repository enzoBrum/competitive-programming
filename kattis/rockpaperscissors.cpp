#include <bits/stdc++.h>
#define sz(x) (int (x.size()))
#define fast_io() {ios::sync_with_stdio(0); cin.tie(NULL);}

typedef long long ll;
typedef uint64_t ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pi> vii;
using namespace std;

enum class Result {
    LOSS,
    TIE,
    WIN
};

pair<Result, Result> win(string a, string b) {
    bool wa = false, wb = false;

    if ( (a == "paper" && b == "rock") || (a == "rock" && b == "scissors") || (a == "scissors" && b == "paper")   )
        wa = true;
    else if ( (b == "paper" && a == "rock") || (b == "rock" && a == "scissors") || (b == "scissors" && a == "paper"))
        wb = true;

    if (wa && wb)
        throw runtime_error("wa and wb");
    else if (wa)
        return make_pair(Result::WIN, Result::LOSS);
    else if (wb)
        return make_pair(Result::LOSS, Result::WIN);
    else if ( a == b)
        return make_pair(Result::TIE, Result::TIE);
}

int main() {
    fast_io();
    
    while (true)
    {
        int n, k;

        cin >> n;
        if (n == 0) break;
        cin >> k;

        int tot = k*n*(n-1)/2;
        vii vec(n);
        
        while (tot--)
        {
            int p1, p2;
            string s1, s2;
            cin >> p1 >> s1 >> p2 >> s2;

            auto[r1, r2] = win(s1,s2);
            if (r1 == Result::WIN)
            {
                vec[p1-1].first++;
                vec[p2-1].second++;
            }
            else if (r2 == Result::WIN)
            {
                vec[p2-1].first++;
                vec[p1-1].second++;
            }   
        }

        for_each(vec.begin(), vec.end(), [k](pi p){
            if ( !p.first && !p.second )
                cout << "-\n";
            else
                cout << fixed << setprecision(3) << p.first / (double) (p.first+p.second) << '\n';
        });
        cout << '\n';

    }
    
}