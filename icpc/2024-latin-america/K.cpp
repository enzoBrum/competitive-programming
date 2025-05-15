#include <bits/stdc++.h>
#include <iostream>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int cur[3][2], nxt[3][2];

int VOWEL = 0, CONSONANT = 1;

bool is_vowel(char c) {
  switch (c) {
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
  case 'Y':
    return true;
  default:
    return false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<string> words(n);
  for (int i = 0; i < n; ++i)
    cin >> words[i];

  memset(cur, 127, sizeof cur);
  cur[0][0] = cur[0][1] = 0;
  for (int i = 0; i < n; ++i) {
    int sz = min((int)words[i].size(), 3);
    memset(nxt, 127, sizeof nxt);

    for (int consecutive_consonants = 0; consecutive_consonants < 3;
         ++consecutive_consonants) {
      for (int letter_type = 0; letter_type < 2; ++letter_type) {
        if (cur[consecutive_consonants][letter_type] > 1e9)
          continue;

        int new_consecutive_consonants = consecutive_consonants;
        bool failure = false;
        for (int j = 0; j < sz && !failure; ++j) {
          if (is_vowel(words[i][j]))
            new_consecutive_consonants = 0;
          else
            new_consecutive_consonants += 1;

          if (is_vowel(words[i][j]))
            nxt[0][VOWEL] =
                min(nxt[0][VOWEL],
                    cur[consecutive_consonants][letter_type] + j + 1);
          else if (new_consecutive_consonants <= 2)
            nxt[new_consecutive_consonants][CONSONANT] =
                min(nxt[new_consecutive_consonants][CONSONANT],
                    cur[consecutive_consonants][letter_type] + j + 1);
          else
            failure = true;
        }
      }
    }

    swap(nxt, cur);
  }

  int ans = 2e9;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 2; ++j)
      ans = min(cur[i][j], ans);
  if (ans > 1e9)
    cout << "*\n";
  else
    cout << ans << '\n';
}
