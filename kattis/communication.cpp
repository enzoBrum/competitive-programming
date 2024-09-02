#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;



/*
010110 --> 22
101100

111010 --> 58
*/

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  while (n--) {
    int ciphertext;
    cin >> ciphertext;

    int solution = 256;
    for (int i = 0; i < 256 && solution == 256; ++i)
      if (((i ^ (i << 1)) & 255) == ciphertext)
        solution = i;
    cout << solution << ' ';
  }
  cout << endl;
}
