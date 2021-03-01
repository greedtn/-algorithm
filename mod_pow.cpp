#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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