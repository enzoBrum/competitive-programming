#include <bits/stdc++.h>
#include <sstream>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

string date, ans;
int best, cnt;
bool used[8];

vector<int> days = {
  31,
  31,
  28,
  31,
  30,
  31,
  30,
  31,
  31,
  30,
  31,
  30,
  31
};

set<tuple<int, int, int>> seen;

bool is_leap(int y) {
  if (y % 400 == 0)
    return true;
  if (y % 100 == 0)
    return false;
  if (y % 4 == 0)
    return true;
  return false;
}

void backtrack(string& cur) {
  if (cur.size() == date.size()) {
    int day = stoi(cur.substr(0, 2));
    int month = stoi(cur.substr(2, 2));
    int year = stoi(cur.substr(4));
    
    if (is_leap(year))
      days[2]++;
    if (month > 12 || month == 0 || day > days[month] || day < 1 || year < 2000) {
      if (is_leap(year))
        days[2]--;
      return;
    }
    int val = (day + accumulate(days.begin()+1, days.begin() + month + 1, 0) + year*365);
    seen.insert({day, month, year});
    if (val < best) {
      best = val;
      ans = cur;
    }
    if (is_leap(year))
      days[2]--;
    return;
  }
  
  for (int i = 0; i < date.size(); ++i) {
    if (used[i])
      continue;

    used[i] = true;
    cur.push_back(date[i]);
    backtrack(cur);
    used[i] = false;
    cur.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  cin.ignore(1024, '\n');
  while (t--) {
    stringstream ss;
    string buf;
    best = 1e9;
    cnt = 0;
    getline(cin, buf);
    ss << buf;
    date.clear();
    ans.clear();
    seen.clear();
    memset(used, 0, sizeof(used));
    while (getline(ss, buf, ' '))
        date += buf;
    buf.clear();
    backtrack(buf);
    if (!ans.size())
      cout << "0\n";
    else
      cout << seen.size() << ' ' << ans.substr(0, 2) + ' ' + ans.substr(2, 2) + ' ' + ans.substr(4) << '\n';
  }
}
