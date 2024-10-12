#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

bool suc = true;
vector<int> vec;
double side  = pow(2, -5.0/4.0);
double height = pow(2, -3.0/4.0);
double area = side*height;

double find_next_side(double goal) {
    double l = 0, r = 1;
    for (int i = 0; i < 50; ++i) {
        double mid = l + (r - l)/2;
        double a = side * mid * height * mid;
        if (a < goal)
            l = mid;
        else
            r = mid;
    }
    return height*l;
}

double solve(int target, int i) {
    //cout << "Target: " << target << ", I: " << i << endl;
    if (i == vec.size()) {
        suc = false;
        return 0;
    }

    double ans = 0;
    if (vec[i] < target)
        ans = solve((target - vec[i])*2, i+1);
    
    //cout << "Target: " << target << ", I: " << i << ", ANS: " << ans << endl;
    
    if (i > 1)
        ans += target/2*find_next_side(area / (1 << (i - 1)));
    else if (i)
        ans += target/2*height;
    return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  vec.resize(n);
  for (int i = 1; i < n; ++i)
      cin >> vec[i];

    double ans = solve(1, 0);
    if (!suc)
        cout << "impossible\n";
    else
        cout << fixed << setprecision(10) << ans << '\n';
}
