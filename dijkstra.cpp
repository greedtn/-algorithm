#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0; i < (n); i++)
using ll = long long;
template<class T> 
bool chmin(T &a, T b) {if (a > b) {a = b;return true;}else return false;}
struct Edge { ll to; ll cost; Edge(ll t, ll c) { to = t; cost = c;} };
using Graph = vector<vector<Edge>>;

const ll INF = 1LL << 60;


int main() {
    ll n, m, s; cin >> n >> m >> s;
    
    Graph G(n);
    rep(i, m) {
        ll a, b, c; cin >> a >> b >> c;
        G[a].push_back(Edge(b, c));
    }

    // ダイクストラ
    vector<bool> used(n, false);
    vector<ll> dist(n, INF);
    dist[s] = 0;
    for (ll iter = 0; iter < n; iter++) {
        // 「使用済み」でない頂点の中からdist値が最小の頂点を探す
        ll min_dist = INF;
        ll min_v = -1; // 最小の頂点を格納する変数, -1のままなら探索終わり
        for (ll v = 0; v < n; v++) {
            if (!used[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }
        }
        if (min_v == -1) break;

        for (auto e : G[min_v]) {
            chmin(dist[e.to], dist[min_v] + e.cost);
        }

        used[min_v] = true;
    }
    for (ll v = 0; v < n; v++) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
    return 0;
}
