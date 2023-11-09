#include <bits/stdc++.h>
#define lili long long int
using namespace std;

//Find the length of LIS
//Time complexity: O(n^2)
int lengthOfLIS(vector<int>& arr) {
	int n = arr.size();
	int lis_len_ending_here[n + 1];
	int lis_len = 1;
	for(int i = 0; i < n; i++) {
		lis_len_ending_here[i] = 1;
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(arr[j] < arr[i] && lis_len_ending_here[j] + 1 > lis_len_ending_here[i]) {
				lis_len_ending_here[i] = lis_len_ending_here[j] + 1;
			}
		}
		lis_len = max(lis_len, lis_len_ending_here[i]);
	}
	return lis_len;
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
