#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;


vector<P> prime_factorize(ll n) {
    vector<P> res;
    for (ll a = 2; a * a <= n; a++) {
        if (n % a != 0) continue;
        ll ex = 0; // 指数

        // 割れる限り割り続ける
        while (n% a == 0) {
            ex++;
            n /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (n != 1) res.push_back({n, 1});
    return res;
}

int main() {
    ll n;
    cin >> n;
    const auto &res = prime_factorize(n);
    cout << n << ":";
    for (auto p : res) {
        for (int i = 0; i < p.second; ++i) cout << " " << p.first;
    }
    cout << endl;
}