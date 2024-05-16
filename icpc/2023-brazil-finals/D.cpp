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
    unordered_map<string, int> mp;
    
    string secret_word;
    cin >> secret_word;
    
    unordered_set<char> st;
    for (auto& c : secret_word)
        st.insert(c);
    mp["*****"] = 1;
    for (int i = 0; i < n - 1; ++i) {
        string guess;
        string curr;
        cin >> curr;
        for (int j = 0; j < 5; ++j) {
            if (curr[j] == secret_word[j])
                guess.push_back('*');
            else if (st.count(curr[j]))
                guess.push_back('!');
            else
                guess.push_back('X');
        }
        //cout << "W=" << curr << " -> " << guess << '\n';
        mp[guess]++;
    }
    
    int g;
    cin >> g;
    
    while (g--) {
        string s;
        cin >> s;
        cout << (mp.count(s) ? mp[s] : 0) << '\n';
    }
}
