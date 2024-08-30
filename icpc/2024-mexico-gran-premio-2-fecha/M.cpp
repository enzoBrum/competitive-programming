#include <bits/stdc++.h>
#include <numeric>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

double volume(double l, double r, double h) {
  double foo = sqrt(l * l - h * h);
  return h * (3 * r * r + foo * (foo + 3 * r));
}

double ternary_search(int length, int radius) {

  double l = 0, r = length;

  while (r - l > 1e-6) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;

    double v1 = volume(length, radius, m1);
    double v2 = volume(length, radius, m2);

    if (v1 < v2)
      l = m1;
    else
      r = m2;
  }
  
  return acos(l/length) + numbers::pi / 2;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {
    int l, r;
    cin >> l >> r;
    cout <<  fixed << setprecision(8) <<  ternary_search(l,r) << '\n';
  }

}
