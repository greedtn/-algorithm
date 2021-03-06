#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0; i < (n); i++)
using ll = long long;
using P = pair<ll, ll>;
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
        a--; b--;
        G[a].push_back(Edge(b, c));
    }
    vector<ll> dist(n, INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(make_pair(dist[s], s));
    
    while (!q.empty()) {
        ll v = q.top().second;
        ll d = q.top().first;
        q.pop();

        if (d > dist[v]) continue;

        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v] + e.cost)) {
                q.push(make_pair(dist[e.to], e.to));
            }
        }
    }
    // 結果出力
    rep(v, n) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }

    return 0;

}