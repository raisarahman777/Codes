#include<bits/stdc++.h>
#define lili long long int
using namespace std;

//nCr in O(n^2)
//Pro: The value of MOD does not have to be prime
//Con: Time complexity and space complexity O(n^2)

const int N = 1001;
const int MOD = 100;
int C[N][N];

void init() {
    for(int i = 0; i < N; i++) {
        C[i][0] = 1;
    }
    for(int i = 1; i < N; i++) {
        for(int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}

void solve() {
    int n, r;
    cin >> n >> r;
    cout << C[n][r] << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int n, r;
    while(cin >> n >> r) {
        cout << C[n][r] << endl;
    }
    return 0;
}