// Cn = 1 / (n + 1) * choose(2n, n)

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
const int N = 1001;
const int MOD = 1000000;
 
ll catalan[N];

void init() {
    catalan[0] = catalan[1] = 1;
    for (int i = 2; i < N; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++) {
            catalan[i] += (catalan[j] * catalan[i - j - 1]) % MOD;
            if (catalan[i] >= MOD) catalan[i] -= MOD;
        }
    }
}
 
void solve() {
	int n;
	while (cin >> n && n != 0) {
	    cout << catalan[n] << endl;
    }
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