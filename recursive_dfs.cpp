#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0; i < (n); i++)
using ll = long long;
using P = pair<ll, ll>;
template<class T> 
bool chmax(T &a, T b) {if (a < b) {a = b;return true;}else return false;}
template<class T> 
bool chmin(T &a, T b) {if (a > b) {a = b;return true;}else return false;}
// struct Edge { ll to; ll cost; Edge(ll t, ll c) { to = t; cost = c;} };
// using Graph = vector<vector<Edge>>;
using Graph = vector<vector<ll>>;
// priority_queue<P, vector<P>, greater<P>> q;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v: G[v]) {
        if (seen[next_v]) continue; // 探索済なら飛ばす
        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {

    // 頂点と辺の数
    ll n, m; cin >> n >> m;

    // グラフの入力を受け取る (ここでは有向グラフを想定)
    Graph G(n);
    rep(i, m) {
        ll a, b; cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
    }

    // 探索
    seen.assign(n, false); // 初期状態では全ての頂点が未探索
    for (ll v = 0; v < n; v++) {
        if (seen[v]) continue;
        dfs(G, v);
    }
}