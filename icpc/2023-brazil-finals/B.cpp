#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<int,int> freq;
    n *= 3;
    while (n--) {
        int v; cin >> v;
        freq[v]++;
    }
    
    for (auto&[_,f] : freq) {
        //cout << _ << '\t' << f << '\n';
        if (f % 3 != 0) {
         cout << "Y\n";
         return 0;
        }
    }
    
    cout << "N\n";
}
