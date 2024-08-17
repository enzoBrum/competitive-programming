#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

bool simulate(deque<int> vec) {
  int old_size = vec.size();
  for (int i = 1; i < old_size; ++i) {
    for (int j = 0; j < i; ++j) {
      int top = vec.front();
      vec.pop_front();

      vec.push_back(top);
    }

    int top = vec.front();

    if (top != i)
      return false;
    vec.pop_front();
  }
  return vec.front() == old_size;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // vector<deque<int>> solutions(14);
  // for (int i = 1; i <= 13; ++i) {
  //   deque<int> curr(i);
  //   iota(curr.begin(), curr.end(), 1);
  //
  //   do {
  //     if (simulate(curr)) {
  //       solutions[i] = curr;
  //       break;
  //     }
  //   } while (next_permutation(curr.begin(), curr.end()));
  //   cout << "{ ";
  //   for (int i = 0; i < curr.size(); ++i) {
  //     cout << curr[i];
  //     if (i != curr.size() - 1)
  //       cout << ", ";
  //   }
  //   cout << "},\n";
  // }

  vector<vector<int>> solutions = {{},
                                   {1},
                                   {2, 1},
                                   {3, 1, 2},
                                   {2, 1, 4, 3},
                                   {3, 1, 4, 5, 2},
                                   {4, 1, 6, 3, 2, 5},
                                   {5, 1, 3, 4, 2, 6, 7},
                                   {3, 1, 7, 5, 2, 6, 8, 4},
                                   {7, 1, 8, 6, 2, 9, 4, 5, 3},
                                   {9, 1, 8, 5, 2, 4, 7, 6, 3, 10},
                                   {5, 1, 6, 4, 2, 10, 11, 7, 3, 8, 9},
                                   {7, 1, 4, 9, 2, 11, 10, 8, 3, 6, 5, 12},
                                   {4, 1, 13, 11, 2, 10, 6, 7, 3, 5, 12, 9, 8}};

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    auto &sol = solutions[n];
    for (auto &s : sol)
      cout << s << ' ';
    cout << '\n';
  }
}
