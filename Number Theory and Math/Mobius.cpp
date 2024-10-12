//Problem: CSES-2417
//Given n integers, count the number of pairs where the numbers are coprime

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e6 + 1;
ll spf[N], mobius[N], cnt[N];

void find_smallest_prime_factor() {
    for (ll i = 2; i < N; i++) {
        if (spf[i] == 0) {
            for (ll j = i; j < N; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
        }
    }
}

void Mobius() {
    mobius[1] = 1;
    for (ll i = 2; i < N; i++) {
        if (spf[i] == spf[i / spf[i]]) {
            mobius[i] = 0;
        }
        else {
            mobius[i] = -1 * mobius[i / spf[i]];
        }
    }
}

void solve() {
    find_smallest_prime_factor();
    Mobius();
    int n;
    cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll ans = 0;
    for (ll i = 1; i < N; i++) {
        if (mobius[i]) {
            ll d = 0;
            for (ll j = i; j < N; j += i) {
                d += cnt[j];
            }
            ans += mobius[i] * ((d * (d - 1)) / 2);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}