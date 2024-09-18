#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

ll cnt = 0;
ll cur = 1;
int l_count = 0;
string s;

inline bool is_vowel(char c) {
  return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

inline bool valid(int i) {
  if (i < 2)
    return true;

  int num = is_vowel(s[i]) + is_vowel(s[i-1]) + is_vowel(s[i-2]);
  return num != 3 && num != 0;
}

void backtrack(int k) {
  if (k == s.size()) {
    if (valid(k-1) && l_count)
      cnt += cur;
    return;
  }
  
  if (s[k] != '_' && valid(k)) {
    if (s[k] == 'L')
      l_count++;
    backtrack(k+1);
    if (s[k] == 'L')
      l_count--;
  } else if (s[k] == '_') {
    // L
    s[k] = 'L';
    l_count++;
    if (valid(k))
      backtrack(k+1);
    l_count--;

    // Vowel
    s[k] = 'A';
    cur *= 5;
    if (valid(k))
      backtrack(k+1);
    
    cur /= 5;
    
    // consonant
    s[k] = 'Z';
    cur *= 20;
    if (valid(k))
      backtrack(k+1);

    cur /= 20;
    s[k] = '_';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> s;
  backtrack(0);
  cout << cnt << '\n';
}
