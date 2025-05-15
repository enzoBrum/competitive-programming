#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r, c, k;
  cin >> r >> c >> k;

  vector<vector<char>> leds(r, vector<char>(c));
  vector<vector<char>> pattern(r, vector<char>(k));

  cin.ignore(1024, '\n');
  for (int i = 0; i < r; ++i) {
    string line;
    getline(cin, line);

    stringstream ss;
    ss << line;

    string leds_row, pattern_row;
    ss >> leds_row >> pattern_row;

    for (int j = 0; j < c; ++j)
      leds[i][j] = leds_row[j];
    for (int j = 0; j < k; ++j)
      pattern[i][j] = pattern_row[j];
  }

  for (int i = 0; i < r; ++i) {
    bool has_led = false;
    for (int j = 0; j < k && !has_led; ++j)
      if (pattern[i][j] != '-')
        has_led = true;
    if (!has_led)
      continue;

    for (int j = 0; j < c; ++j)
      if (leds[i][j] == '-') {
        cout << "N\n";
        return 0;
      }
  }
  cout << "Y\n";
}
