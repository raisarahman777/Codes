//CSES-1643
//Maximum subarray (non-empty) sum

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 2e5 + 5;
ll a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll curr_sum = a[1];
    ll max_sum = a[1];
    for (int i = 2; i <= n; i++) {
        if (curr_sum < 0) curr_sum = 0;
        curr_sum += a[i];
        max_sum = max(max_sum, curr_sum);
    }
    cout << max_sum << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
