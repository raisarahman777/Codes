#include <bits/stdc++.h>
#define lili long long int
using namespace std;

//Find the length of LIS
//Time complexity: O(nlogn)
int lengthOfLIS(vector<int>& arr) {
	int n = arr.size();
	vector<int> ans;
	ans.push_back(arr[0]);
	for(int i = 1; i < arr.size(); i++) {
		if(arr[i] > ans.back()) {
			ans.push_back(arr[i]);
		}
		else {
			int ind = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
			ans[ind] = arr[i];
		}
	}
	return ans.size();
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
