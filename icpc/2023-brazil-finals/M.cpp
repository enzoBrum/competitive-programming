#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include <functional>
#include<map>

using namespace std;
using pii = pair<int,int>;

vector<int> dijkstra(vector<vector<pii>>& adj, int origin, int ignore = 1e9) {
    vector<int> d(adj.size(), 1e9);
    d[origin] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, origin});
    while (!pq.empty()) {
        auto[w, u] = pq.top();
        pq.pop();
        
        if (w != d[u])
            continue;
        
        for (auto&[wv, v] : adj[u]) {
            if (d[u] + wv >= d[v] || v == ignore)
                continue;
            
            d[v] = d[u] + wv;
            pq.push({d[v], v});
        }
    }
    
    return d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    
    int p, g;
    cin >> p >> g;
    
    p--;
    g--;
    
    vector<vector<pii>> adj(n);
    
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        adj[u].push_back({d,v});
        adj[v].push_back({d,u});
    }
    
    auto d1 = dijkstra(adj, p);
    map<int, int> mp;
    
    /*cout << "P=" << p << ",G=" << g << endl;
    for (int i = 0; i < n; ++i)
        cout << i+1 << "=" << d1[i] << endl;
    */
    for (int i = 0; i < n; ++i) {
        if (d1[i] == 2*d1[g])
            mp[i] = d1[i];
    }
    
    auto d2 = dijkstra(adj, p, g);
    //cout << "MP=" << mp.size() << endl;
    bool success = false;
    for (auto&[u, w] : mp) {
        if (d2[u] == w)
            continue;
        cout << u+1 << ' ';
        success = true;
    }
    
    if (!success)
        cout << '*';
    
    cout << '\n';
}

