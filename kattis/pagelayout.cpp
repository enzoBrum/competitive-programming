#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

struct Rectangle {
  int x, y, w, h;
};

char used[20];
char fit[20];
ll suf[21], area[20];

bool intersections[20][20];

int n;
ll best, cur_sum;

inline bool intersect(const Rectangle* a, const Rectangle* b) {
  if (a->x > b-> x)
    swap(a, b);
  
  if (a->x + a->w - 1 < b->x || a->y + a->h - 1 < b->y || b->y + b->h - 1 < a->y )
    return false;
  return true;
}

void backtrack(int k, int last = -1) {
  best = max(best, cur_sum);
  if (k == n) {
    return;
  }
  
  if (suf[k] + cur_sum <=  best)
    return;
  
  for (int i = last + 1; i < n; ++i) {
    if (!fit[i])
      continue;
    // use
    bool inter = false;
    for (int j = 0; j < i && !inter; ++j)
      if (intersections[i][j] && i != j && used[j])
        inter = true;
    
    if (inter)
      continue;
    
    used[i] = true;
    cur_sum += area[i];
    backtrack(k+1, i);
    cur_sum -= area[i];
    used[i] = false;
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  while (cin >> n && n) {
    best = cur_sum = 0;
    memset(used, 0, sizeof(used));
    memset(intersections, 0, sizeof(intersections));
    
    vector<Rectangle> rects(n);
    for (auto& r : rects)
      cin >> r.w >> r.h >> r.x >> r.y;
    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j)
        if (intersect(&rects[i], &rects[j]))
          intersections[i][j] = intersections[j][i] = true;
    for (int i = 0; i < n; ++i)
      area[i] = rects[i].w * rects[i].h, fit[i] = rects[i].x + rects[i].w <= 1000 && rects[i].y + rects[i].h <= 1000;
    
    suf[n-1] = area[n-1];
    for (int i = n-2; i >= 0; --i)
      suf[i] = suf[i+1] + area[i];
    
    backtrack(0);

    cout << best << '\n';
  }


}
