#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void debug(int i, multiset<int> &lo, multiset<int> &hi) {
  cout << "I: " << i << '\n';
  cout << "LO: ";
  for (auto &v : lo)
    cout << v << ' ';
  cout << "\nHI: ";
  for (auto &v : hi)
    cout << v << ' ';

  cout << "\nMEDIAN: " << *lo.rbegin() << "\n\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;

  multiset<int> lo, hi;
  for (int i = 0; i < k; ++i)
    lo.insert(vec[i]);

  for (int i = 0; i < k / 2; ++i) {
    int tmp = *lo.rbegin();
    lo.erase(prev(lo.end()));
    hi.insert(tmp);
  }

  int median = *lo.rbegin();
  cout << median << ' ';

  // debug(k - 1, lo, hi);

  for (int i = k; i < n; ++i) {
    int tmp = vec[i];

    if (k == 1) {
      cout << vec[i] << ' ';
      continue;
    }

    if (tmp > median)
      hi.insert(tmp);
    else
      lo.insert(tmp);

    int to_remove = vec[i - k];
    if (to_remove > median)
      hi.erase(hi.find(to_remove));
    else
      lo.erase(lo.find(to_remove));

    if (hi.size() > lo.size()) {
      int tmp = *hi.begin();
      hi.erase(hi.find(*hi.begin()));
      lo.insert(tmp);
    } else if (lo.size() > hi.size() + 1) {
      int tmp = *lo.rbegin();
      lo.erase(lo.find(*prev(lo.end())));
      hi.insert(tmp);
    }

    median = *lo.rbegin();
    // debug(i, lo, hi);
    cout << median << ' ';
  }
  cout << '\n';
}
