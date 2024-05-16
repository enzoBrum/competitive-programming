#include <bits/stdc++.h>
#define sz(x) (int (x.size()))
#define fast_io() {ios::sync_with_stdio(0); cin.tie(NULL);}

typedef long long ll;
typedef uint64_t ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pi> vii;
using namespace std;


int main() {
  int n, k;
  vi vec = {0};
  queue<pi> qq;
  queue<int> qid;
  unordered_set<int> sid;
  qid.push(0);
  sid.insert(0);

  cin >> n >> k;

  while (n--) {
    int t, id = 0;
    cin >> t;

    while (!qq.empty() && qq.front().second + 1000 <= t) {
      id = qq.front().first;
      vec[id]--;

      if (!sid.count(id)) {
        qid.push(id);
        sid.insert(id);
      }
      qq.pop();
    }

    if ( qid.empty() ) {
      vec.push_back(1);
      id = vec.size() - 1;
      qid.push(id);
      sid.insert(id);
    }

    else {
      id = qid.front();
      vec[id]++;

    }

    if (vec[id] == k) {
      qid.pop();
      sid.erase(id);
    }
    qq.emplace(id, t);
  }

  cout << vec.size() << '\n';
}
