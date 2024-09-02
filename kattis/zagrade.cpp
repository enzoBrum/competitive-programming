#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

set<string> ans;
vector<int> pairs;
string s;

void backtrack(int i) {
  if (i == s.size()) {
    string cur;
    for (auto& c : s)
      if (c != 'Z')
        cur.push_back(c);
    ans.insert(cur);
    return;
  }
  
  if (pairs[i] != -1) {
    s[i] = s[pairs[i]] = 'Z';
    backtrack(i+1);
    s[i] = '(';
    s[pairs[i]] = ')';
  }
  backtrack(i+1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> s;
  pairs.assign(s.size(), -1);
  stack<int> st;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(')
      st.push(i);
    else if (s[i] == ')')
      pairs[st.top()] = i, st.pop();
  }
  
  backtrack(0);
  for (auto& a : ans) {
    if (a == s)
      continue;
    for (auto& c : a)
        cout << c;
      cout << '\n';
  }

}
