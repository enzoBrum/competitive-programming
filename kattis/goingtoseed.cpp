#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;


int main() {
    int n;
    cin >> n;
    
    int l = 1, r = ++n;

    while (l < r) {
        int q2 = (l+r)/2;
        int q1 = (l+q2)/2;
        int q3 = (q2+r)/2;
        
        cout << "Q " << l << ' ' << q2 - 1 << ' ' << q1 << ' ' << q3 - 1 << endl;
        int w1, w2;
        cin >> w1 >> w2;

        if (w1 && w2)
            l = q1, r = q2;
        else if (w1)
            r = q1;
        else if (w2)
            l = q2, r = q3;
        else
            l = q3;

        if (l == r - 1) {
            cout << "A " << l << endl;
            return 0;
        }
        l = max(l - 1, 1), r = min(r+1, n);
    }
    cout << "A " << l << endl;
}