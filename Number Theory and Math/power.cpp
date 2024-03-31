#include<bits/stdc++.h>
#define lili unsigned long long int
using namespace std;

const int MOD = 998244353;

//Recursive
int pow(int a, int b, int mod) {
    if (b == 0) {
        return 1;
    }
    int res = pow(a, b / 2, mod) % mod;
    res = ((lili)res * res) % mod;
    if (b & 1) {
        res = ((lili)res * a) % mod;
    }
    return res;
}

lili mulmod(lili a, lili b, lili m) { //a * b mod m
    lili res = 0;
    lili x = a % m;
    while (b) {
        if (b & 1) {
            res = (res + x) % m;
        }
        x = (x + x) % m;
        b >>= 1;
    }
    return res;
}

//Iterative
lili bigmod(lili a, lili b, lili m) { //a ^ b mod m
    lili res = 1 % m;
    lili x = a;
    while (b) {
        if (b & 1) {
            res = mulmod(res, x, m) % m;
        }
        x = mulmod(x, x, m) % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    lili a, b, m;
    while (cin >> a >> b >> m) {
        cout << bigmod(a, b, m) << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    int case_no = 1;
    while (t--) {
        //cout << "Case " << case_no++ << ": ";
        solve();
    }
    return 0;
}