#include <bits/stdc++.h>
#include <sstream>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string line;
  while (getline(cin, line)) {
    if (line.size() == 0)
      break;

    stringstream ss;
    ss << line;

    vector<int> vec;
    int num;
    int largest = -1;
    while (ss >> num) {
      largest = max(largest, num);
      vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    
    vector<int> freq(largest + 1);
    for (int i = 0; i < vec.size(); ++i) {
      for (int j = i+1; j < vec.size(); ++j)
        freq[vec[j] - vec[i]]++;
    }
    
    vector<int> missing;
    bool is_ruler = true;
    for (int i = 1; i < freq.size() && is_ruler; ++i) {
      if (freq[i] > 1)
        is_ruler = false;
      else if (freq[i] == 0)
        missing.push_back(i);
    }
    
    if (!is_ruler)
      cout << "not a ruler\n";
    else if (!missing.size())
      cout << "perfect\n";
    else {
      cout << "missing ";
      for (auto& m : missing)
        cout << m << ' ';
      cout << '\n';
    }
  }

}