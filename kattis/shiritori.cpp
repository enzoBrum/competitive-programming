#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  unordered_set<string> words;

  int player = 0;
  string last;
  while (n--) {
    string w;
    cin >> w;

    bool success = (!last.size() || last.back() == w[0]) && !words.count(w);
    if (!success) {
      cout << "Player " << player + 1 << " lost\n";
      return 0;
    }
    words.insert(w);
    last = w;

    player = 1 - player;
  }
  cout << "Fair Game\n";
}
