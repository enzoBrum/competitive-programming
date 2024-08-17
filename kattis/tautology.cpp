#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;


pair<bool,int> solve(string& word, int idx, const vector<int>& vec) {
  // this should not happen.
  if (idx == word.size())
    throw runtime_error("AAAA");
  
  switch (word[idx]) {
    case 'K': {
      auto[w, iw] = solve(word, idx+1, vec);
      auto[x, ix] = solve(word, iw+1, vec);
      
      return { w && x, ix };
    }
    case 'A': {
      auto[w, iw] = solve(word, idx+1, vec);
      auto[x, ix] = solve(word, iw+1, vec);
      
      return { w || x, ix };
    }
    case 'N': {
      auto[w, iw] = solve(word, idx+1, vec);
      return {!w, iw};
    }
    case 'C': {
      auto[w, iw] = solve(word, idx+1, vec);
      auto[x, ix] = solve(word, iw+1, vec);
      
      return { !(w && !x), ix };
    }
    case 'E': {
      auto[w, iw] = solve(word, idx+1, vec);
      auto[x, ix] = solve(word, iw+1, vec);
      
      return { w == x, ix };
    }
    default: {
      return { vec[word[idx] - 'p'] == 1, idx};
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string word;
  while (cin >> word) {
    if (word == "0")
      break;

    bool taut = true;
    for (int p = 0; p <= 1 && taut; ++p)
      for (int q = 0; q <= 1 && taut; ++q)
        for (int r = 0; r <= 1 && taut; ++r)
          for (int s = 0; s <= 1 && taut; ++s)
            for (int t = 0; t <= 1 && taut; ++t)
              taut = taut && solve(word, 0, {p, q, r, s, t}).first;              
    cout << (taut ? "tautology" : "not") << '\n';
  }
}
