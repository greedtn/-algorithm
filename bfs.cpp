#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0; i < (n); i++)
using ll = long long;
using Graph = vector<vector<ll>>;

// sからi(0 <= i < n)までの距離をdist[i]に格納する関数
vector<ll> BFS(const Graph &G, ll s) {
    ll n = (ll)G.size();
    vector<ll> dist(n, -1);
    queue<ll> que;

    dist[s] = 0;
    que.push(s);
    
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
        // 問題によっては, a-1やb-1にしないといけないので注意!!
        ll a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 始点が0のときはこのコード
    vector<ll> dist = BFS(G, 0);
    for (ll v = 0; v < n; v++) cout << v << ": " << dist[v] << endl;
    return 0;
}