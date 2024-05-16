#include<numeric>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

#define sz(x) (int) x.size()

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  bool first = true;
  while (!cin.eof()) {
    if (first) first = false;
    else cout << '\n';
    
    string line;
    vector<string> vec;

    while (getline(cin, line) && line != "") {
      reverse(line.begin(), line.end());
      vec.push_back(line);
    }

    sort(vec.begin(), vec.end());
    int max_size  = 0;
    for (auto& s : vec) max_size = max(max_size, sz(s));

    for (auto& s : vec) {
      reverse(s.begin(), s.end());
      cout << setw(max_size) << s << '\n';
    }
  }
}
