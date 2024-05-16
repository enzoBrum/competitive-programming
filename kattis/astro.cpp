#include <bits/stdc++.h>

#define sz(x) (int (x.size()))
#define fast_io() {ios::sync_with_stdio(0); cin.tie(NULL);}

typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pi> vii;
using namespace std;

string to_hours(int m) {
    int hours = m/60;
    int minutes = m%60;

    string h = to_string(hours);
    if (hours < 10) {
        h = '0' + h;
    }

    string mm = to_string(minutes);
    if (minutes < 10)
        mm = '0' + mm;

    return h + ":" + mm;
}

int to_minutes(string& s) {
    string h = s.substr(0, 2);
    string m = s.substr(3, 2);

    return stoi(h)*60 + stoi(m);
}

int main() {
    string first, second, t_first, t_second;
    cin >> first >> second >> t_first >> t_second;


    int f = to_minutes(first);
    int s = to_minutes(second);
    int ft = to_minutes(t_first);
    int st = to_minutes(t_second);

    vector<bool> vec((int)1e7);
    for ( int i = f; i < sz(vec); i += ft )
        vec[i] = true;
    
    vector<string> days = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    for ( int i = s; i < sz(vec); i += st ) {
        if ( vec[i] ) {
            int d = (i / 1440) % 7;
            i = i % 1440 ;
            cout << days[d] << '\n'
                << to_hours(i)
                << '\n';
            return 0;
        }
    }

    cout << "Never\n";

}