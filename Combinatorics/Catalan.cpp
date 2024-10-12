// Cn = 1 / (n + 1) * choose(2n, n)

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
const int N = 1e6 + 3;
const int MOD = 1e9 + 7;
 
ll fact[N], inv[N];
 
ll bigmod(ll a, ll b, ll m) { //a ^ b mod m
    ll res = 1 % m;
    ll x = a;
    while (b) {
        if (b & 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        b >>= 1;
    }
    return res;
}
 
ll modInverse(ll a, ll m) {
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
 
ll C(ll n, ll r) {
    if (n < r || n < 0) {
        return 0;
    }
    ll res = ((fact[n] * inv[r]) % MOD * inv[n - r]) % MOD;
    return res;
}
 
ll catalan(ll n) {
	ll ans = C(2 * n, n);
	ans *= modInverse(n + 1, MOD);
	ans %= MOD;
	return ans;
}
 
void solve() {
	int n;
	cin >> n;
	if (n & 1) {
		cout << 0 << "\n";
		return;
	}
	n /= 2;
	cout << catalan(n) << "\n";
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

//Raisa