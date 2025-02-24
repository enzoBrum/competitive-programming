#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;


/**
dp[N][0] = 0;

if dp[i][w-1] != -1:
  for p in prices:
    dp[i-s][w] = max(
      dp[i-s][w],
      dp[i][w-1] + p*s
    )


 */
int dp[301], ndp[301];
int og_p[301], nog_p[301];
int prices[100][54];
int seats[100][54];
int sizes[53];

int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  
  int n, w;
  cin >> n >> w;

  for (int i = 1; i <= w+1; ++i) {
    int k;
    cin >> k;

    sizes[i] = k;
    for (int j = 0; j < k; ++j)
      cin >> prices[j][i];
    for (int j = 0; j < k; ++j)
      cin >> seats[j][i];
  }
  
  memset(og_p, 127, sizeof(og_p));
  memset(dp, -1, sizeof(dp));
  memset(nog_p, 127, sizeof(nog_p));
  memset(ndp, -1, sizeof(ndp));
  
  for (int i = 0; i < sizes[1]; ++i)
    ndp[n-seats[i][1]] = prices[i][1] * seats[i][1], nog_p[n - seats[i][1]] = prices[i][1];
  
  for (int week = 2; week <= w+1; ++week) {
    swap(dp, ndp);
    swap(og_p, nog_p);
    
    ndp[0] = dp[0];
    nog_p[0] = og_p[0];
    for (int seats_left = 1; seats_left <= n; ++seats_left) {
      ndp[seats_left] = -1;
      nog_p[seats_left] = -1;
      if (dp[seats_left] == -1)
        continue; 

      int sz = sizes[week];
      for (int i = 0; i < sz; ++i) {

        int bought_seats = min(seats_left, seats[i][week]);
        int new_profit = dp[seats_left] + prices[i][week] * bought_seats;
        if (ndp[seats_left-bought_seats] < new_profit || (ndp[seats_left-bought_seats] == new_profit && nog_p[seats_left-bought_seats] > og_p[seats_left] ))
          ndp[seats_left-bought_seats] = new_profit, nog_p[seats_left-bought_seats] = og_p[seats_left];// printf(
        //"seats_left=%d, dp[%d][%d]=%d, og_p[%d][%d]=%d, seats[%d][%d]=%d, prices[%d][%d]=%d, bought_seats=%d\n", 
        //seats_left,
        //seats_left-bought_seats, 
        //week, 
        //ndp[seats_left-bought_seats], 
        //seats_left-bought_seats, 
        //week, 
        //nog_p[seats_left-bought_seats],
        //i,
        //week,
        //seats[i][week],
        //i,
        //week,
        //prices[i][week],
        //bought_seats
        //);
      }
    }
  }
  
  int ans = 0, og = -1;
  for (int i = 0; i <= n; ++i)
    if (ans < ndp[i])
      ans = ndp[i], og = nog_p[i];
  cout << ans << '\n' << og << '\n';
}
