#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;

class SuffixArray {
private:
  vi RA;                              // rank array
  void countingSort(int k) {          // O(n)
    int maxi = max(300, n);           // up to 255 ASCII chars
    vi c(maxi, 0);                    // clear frequency table
    for (int i = 0; i < n; ++i)       // count the frequency
      ++c[i + k < n ? RA[i + k] : 0]; // of each integer rank
    for (int i = 0, sum = 0; i < maxi; ++i) {
      int t = c[i];
      c[i] = sum;
      sum += t;
    }
    vi tempSA(n);
    for (int i = 0; i < n; ++i) // sort SA
      tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    swap(SA, tempSA); // update SA
  }
  void constructSA() { // can go up to 400K chars
    SA.resize(n);
    iota(SA.begin(), SA.end(), 0); // the initial SA
    RA.resize(n);
    for (int i = 0; i < n; ++i)
      RA[i] = T[i];                   // initial rankings
    for (int k = 1; k < n; k <<= 1) { // repeat log_2 n times
      // this is actually radix sort
      countingSort(k); // sort by 2nd item
      countingSort(0); // stable-sort by 1st item
      vi tempRA(n);
      int r = 0;
      tempRA[SA[0]] = r;          // re-ranking process
      for (int i = 1; i < n; ++i) // compare adj suffixes
        tempRA[SA[i]] = // same pair => same rank r; otherwise, increase r
            ((RA[SA[i]] == RA[SA[i - 1]]) &&
             (RA[SA[i] + k] == RA[SA[i - 1] + k]))
                ? r
                : ++r;
      swap(RA, tempRA); // update RA
      if (RA[SA[n - 1]] == n - 1)
        break; // nice optimization
    }
  }

public:
  const char *T; // the input string
  const int n;   // the length of T
  vi SA;         // Suffix Array
  SuffixArray(const char *initialT, const int _n) : T(initialT), n(_n) {
    constructSA(); // O(n log n)
  };
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;

  s.push_back('$');

  SuffixArray arr(s.c_str(), s.size());

  //for (int i = 0; i < arr.SA.size(); i++) {
  //  int idx = arr.SA[i];
  //  cout << i << '(' << idx << ')' << " --> " << s.substr(idx) << '\n';
  //}

  int n;
  cin >> n;

  int ql = 0, qr = 0;
  auto lcmp = [&ql, &s](int a, int b) { return s[a + ql] < b; };
  auto rcmp = [&ql, &s](int a, int b) { return a < s[b + ql]; };
  while (n--) {
    ql = qr = 0;
    int ans = 0;
    string query;
    cin >> query;


    string curr;

    bool success = true;
    while (ql < query.size()) {
      int l = 0, r = arr.SA.size();
      bool found = false;
      int old_ql = ql;
      ql = 0;
      while (1) {
        int old_l = l;
        l = lower_bound(arr.SA.begin() + l, arr.SA.begin() + r, query[old_ql + ql],
                        lcmp) -
            arr.SA.begin();
        
        char val = query[old_ql + ql]+1;
        r = lower_bound(arr.SA.begin() + old_l, arr.SA.begin() + r, val,
                        lcmp) - 
            arr.SA.begin();

        //cout << "L=" << l << ",R=" << r << ",ql=" << ql << ",query[ql]=" << query[old_ql+ ql] << '\n';

        if (l == r)
          break;

        ql++;
        found = true;
      }

      if (!found) {
        success = false;
        break;
      }

      ans++;
      ql = old_ql + ql;
    }

    cout << (success ? ans : -1) << '\n';
  }
}

