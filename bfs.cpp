#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0; i < (n); i++)
using ll = long long;
using Graph = vector<vector<ll>>;


vector<ll> BFS(const Graph &G, ll s) {
    ll n = (ll)G.size();
    vector<ll> dist(n, -1);
    queue<ll> que;

    dist[0] = 0;
    que.push(0);
    
    while (!que.empty()) {
        ll v = que.front();
        que.pop();

        for (ll x: G[v]) {
            if (dist[x] != -1) continue;
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main() {
    ll n, m; cin >> n >> m;
    Graph G(n);
    rep(i, m) {
        ll a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> dist = BFS(G, 0);
    for (ll v = 0; v < n; v++) cout << v << ": " << dist[v] << endl;
    return 0;
}