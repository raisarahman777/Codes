#include<bits/stdc++.h>
#define lili long long int
using namespace std;

//LightOJ - 1067

const int N = 1e6 + 3;
const int MOD = 1000003;

lili fact[N], inv[N];

lili bigmod(lili a, lili b, lili m) { //a ^ b mod m
    lili res = 1 % m;
    lili x = a;
    while (b) {
        if (b & 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        b >>= 1;
    }
    return res;
}

lili modInverse(lili a, lili m) {
    return bigmod(a, m - 2, m);
}

void init() {
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv[N - 1] = modInverse(fact[N - 1], MOD);
    for(int i = N - 2; i >= 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    }
}

lili C(lili n, lili r) {
    if (n < r || n < 0) {
        return 0;
    }
    lili res = ((fact[n] * inv[r]) % MOD * inv[n - r]) % MOD;
    return res;
}

void solve() {
    int n, r;
    cin >> n >> r;
    cout << C(n, r) << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int t = 1;
    cin >> t;
    int case_no = 1;
    while (t--) {
        cout << "Case " << case_no++ << ": ";
        solve();
    }
    return 0;
}