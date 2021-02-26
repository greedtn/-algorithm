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
// using Graph = vector<vector<ll>>;
// priority_queue<P, vector<P>, greater<P>> q;

// a^n % p を計算する関数
ll mod_pow(ll a, ll n, ll mod) {
    ll res = 1;
    // n を 2進数に変換して考える
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << mod_pow(a, mod_pow(b, c, 4) + 4, 10) << endl;
} 