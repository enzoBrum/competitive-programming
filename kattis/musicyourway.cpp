#include<iostream>
#include <string>
#include <unordered_map>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

vector<string> split(string& s) {
  stringstream ss(s);
  vector<string> vec;
  string word;
  while (ss >> word) vec.push_back(word);
  return vec;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  
  string line;
  getline(cin, line);

  vector<string> attributes = split(line);

  unordered_map<string, int> attr_to_idx;
  for (int i = 0; i < attributes.size(); ++i) attr_to_idx[attributes[i]] = i;

  int m; cin >> m;
  cin.ignore(1024, '\n');

  vector<vector<string>> songs;
  for (int i = 0; i < m; ++i) {
    string tmp; getline(cin, tmp);
    vector<string> song = split(tmp);
    songs.emplace_back(song);
  }

  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    string attr; cin >> attr;
    int idx = attr_to_idx[attr];
    stable_sort(songs.begin(), songs.end(), [idx](const vector<string>& a, const vector<string>& b){ return a[idx] < b[idx]; });

    for (int j = 0; j < attributes.size(); ++j)
      cout << attributes[j] << ( j == attributes.size() - 1 ? "\n" : " " );
    for (int j = 0; j < songs.size(); ++j)
      for (int k = 0; k < songs[j].size(); ++k)
        cout << songs[j][k] << ( k == songs[j].size() - 1 ? "\n" : " " );

    if (i != n - 1) cout << '\n';
  }
}
