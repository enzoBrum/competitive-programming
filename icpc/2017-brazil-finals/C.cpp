#include <bits/stdc++.h>
#include <string>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int k, n;
  cin >> k >> n;

  vector<int> vec(n);
  vector<int> freq(k + 1, 0);

  for (auto &v : vec) {
    cin >> v;
    freq[v]++;
  }

  int last = freq[1];
  string op;
  bool suc = true;

  int diff = 0, num_min = 1e9, num_max = -1;
  int last2 = -1;

  map<int, int> numbers;
  for (int i = 1; i <= k; ++i)
    numbers[freq[i]]++;

  if (numbers.size() > 3 ||
      (numbers.size() == 3 && numbers.begin()->second != 1) ||
      (numbers.size() == 3 && numbers.rbegin()->second != 1) ||
      (numbers.size() == 2 && numbers.begin()->second != 1 &&
       numbers.rbegin()->second != 1) ||
      (numbers.size() == 2 && numbers.begin()->second != 1 &&
       numbers.begin()->first == 0) ||
      (numbers.rbegin()->first - numbers.begin()->first > 2)) {
    cout << "*\n";
    return 0;
  }

  int a, b;
  for (int i = 1; i <= k; ++i)
    if (freq[i] == numbers.begin()->first)
      a = i;
    else if (freq[i] == numbers.rbegin()->first)
      b = i;

  if (numbers.size() == 3) {

    cout << "-" << b << " +" << a << '\n';
  } else {
    if (numbers.begin()->second == 1)
      cout << "+" << a;
    else
      cout << "-" << b;
  }
}
