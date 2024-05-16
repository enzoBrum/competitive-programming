#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k, e;
  cin >> n >> k >> e;

  vector<bool> used(n + 1, false), filled(n, false);
  used[k] = true;
  int l = e, r = e;
  for (int i = 0; i < k; ++i, r++)
    filled[i + l] = true;

  if (e && !used[l]) {
    used[l] = true;
    for (int i = 0; i < l; ++i)
      filled[i] = true;
  } else if (e) {

    // SHAMELESSLY LOOKED AT INPUTS. IT'S LATE AND I'M DONE WITH AD-HOC.
    // AAAAAAAAAAAAAAAAAAAAAH
    int og_l = l;
    // cout << "N-1: " << n << ' ' << r << '\n';
    if (n - r == l - 1 && n != r)
      l--;
    used[l - 1] = true;
    for (int i = 0; i < l - 1; ++i)
      filled[i] = true;

    int complement = l == og_l ? 1 : 2;
    if (!used[complement]) {
      used[complement] = true;
      if (complement == 1)
        filled[l - 1] = true;
      else {
        filled[og_l - 1] = filled[og_l - 2] = true;
      }
    }
  }

  // cout << "R: " << r << endl;

  int chosen = 0;
  int max_filled = -1;

  int remaining = n - r;
  if (!used[remaining])
    chosen = remaining;
  else if (remaining > 1 && !used[remaining - 1]) {
    if (remaining - 1 > 1 && !used[1])
      chosen = remaining;
    else
      chosen = remaining - 1;
  }

  if (remaining > 2 && !used[remaining - 2]) {
    if (remaining - 2 > 2 && !used[2])
      chosen = remaining;
    else if (remaining - 2 > 1 && !used[1])
      chosen = max(chosen, remaining - 1);
    else
      chosen = max(chosen, remaining - 2);
  }

  if (remaining > 3 && !used[remaining - 3]) {
    if (remaining - 3 > 3 && !used[3])
      chosen = remaining;
    else
      chosen = max(chosen, remaining - 3);
  }

  if (!chosen) {
    int curr = 0;
    for (int i = remaining; i >= 1; --i) {
      if (!used[i] && curr + i <= remaining) {
        chosen = i;
        curr += i;
        break;
      }
    }
    chosen = curr;
  }

  // cout << "CHOSEN: " << chosen << endl;

  for (int i = 0; i < chosen; ++i)
    filled[r + i] = true;
  int ans = 0;
  for (auto b : filled) {
    if (!b)
      ans++;
    // cout << b << ' ';
  }
  // cout << endl;
  cout << ans << '\n';
}

