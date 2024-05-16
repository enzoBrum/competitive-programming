#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<set>
#include<iterator>

using namespace std;
using pii = pair<int, int>;

vector<vector<int>> tree;
vector<int> parents;
vector<vector<int>> subtree_leafs;
vector<int> depth;
set<pii> leafs;
vector<bool> active;
int ans = 0;

void dfs(int u, int d = 1) {
  depth[u] = d;
  if (!tree[u].size()) {
    leafs.insert({d, u});
    //subtree_leafs[parents[u]].push_back(u);
    return;
  }
  
  for (auto& v : tree[u]) {
    dfs(v, d+1);
    
    //for (auto& l : subtree_leafs[v])
    //  subtree_leafs[u].push_back(l);
  }
}

void dfs2(int u, int old_d, int d = 1) {
  if (!active[u]) return;
  
  depth[u] = d;
  if (!tree[u].size()) {
    //cout << "Aaa: " << old_d << ' ' << u+1 << endl;
    leafs.erase({old_d, u});
    leafs.insert({d, u});
    return;
  }
  
  for (auto& v : tree[u])
    dfs2(v, old_d+1, d+1);
}

void propagate(int u, unordered_set<int>& visited) {
  if (!active[u]) return;
  ans++;
  //cout << u+1 << '\n';
  
  active[u] = false;
  
  for (auto& v : tree[u]) {
    dfs2(v, depth[u]+1);
  }
  
  if (parents[u] != -1)
    propagate(parents[u], visited);
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int n, k; cin >> n >> k;

  tree.resize(n);
  subtree_leafs.resize(n);
  depth.assign(n, 0);
  parents.assign(n, -1);
  active.assign(n, true);
  for (int i = 0; i < n - 1; ++i) {
    int boss; cin >> boss;
    boss--;
    
    tree[boss].push_back(i+1);
    //cout << "Boss: " << boss+1 << ", child: " << i+2<< endl;
    parents[i+1] = boss;
  }
  
  //for (auto& v : tree[3]) {
  // cout << v +1<< ' ';
  //}
  //cout << '\n';
  
  dfs(0);
  

  
  for (int i = 0; i < k && leafs.size(); ++i) {
    int l = leafs.rbegin()->second;
    leafs.erase(prev(leafs.end()));
    
    unordered_set<int> visited;
    propagate(l, visited);
      //for (auto&[a,b] : leafs) {
    //cout << a+1 << ' ' << b+1 << '\n';
  //}
  }
  
  cout << ans << '\n';
}

