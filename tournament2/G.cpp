#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  set<int> towers2;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    towers2.insert(tmp);
  }

  vector<int> towers(towers2.begin(), towers2.end());

  // 0 --> A
  // 1 --> B
  int winner = 0;

  int round = 0;
  int diff = 0;

  vector<int> diffs(towers.size());
  int diff2 = 0;

  diffs[0] = towers[0];
  diff = towers[0];
  for (int i = 1; i < towers.size(); ++i)
    diffs[i] = towers[i] - diff, diff += (towers[i] - diff);

  vector<int> final_diffs;
  for (auto& d : diffs)
    if (d > 0)
      final_diffs.push_back(d);//, cout << d << ' ';
  //cout << '\n';

  vector<int> counts(final_diffs.size());
  int cnt = 0;
  for (int i = final_diffs.size() - 1; i >= 0; --i)
    counts[i] = cnt, cnt += (final_diffs[i] == 1);

  for (int i = 0; i < towers.size(); ++i) {
    if (final_diffs[i] == 1 || i == final_diffs.size() - 1 || counts[i] % 2 == 0) {
      //cout << "I: " << i << endl;
      round = 1 - round;
    }
  }

  cout << (1 - round == 1 ? "Bobius" : "Alicius") << '\n';
}
