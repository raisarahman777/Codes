#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//UVA-10104

int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = extended_gcd(b, a % b, x, y);
    int temp = y;
    y = x - (a / b) * y;
    x = temp;
    return r;
}

void solve() {
    int x, y;
    int a, b;
    while (cin >> a >> b) {
        int d = extended_gcd(a, b, x, y);
        cout << x << " " << y << " " << d << "\n";
    }
    return;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
    // cin >> t;
    int tc = 1;
    while (t--) {
        // cout << "Case " << tc++ << ": ";
        solve();
    }
	return 0;
}
