#include <bits/stdc++.h>
#define lili long long int
using namespace std;

//Find the length of LIS
//Time complexity: O(nlogn)
int lengthOfLIS(int* a, int n) {
    lili dp[n + 1];
    dp[0] = -INF;
    for(int i = 1; i <= n; i++) dp[i] = INF;
    for(int i = 1; i <= n; i++) {
        int l = upper_bound(dp, dp + n + 1, a[i]) - dp;
        if(dp[l - 1] < a[i] && a[i] < dp[l]) dp[l] = a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if(dp[i] < INF) ans = i;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& it : a) {
		cin >> it;
	}
	int lis_len = lengthOfLIS(a);
	cout << lis_len << "\n";
    return 0;
}

/*
8
-7 10 9 2 3 8 8 6

Output: 4
*/
