#include <bits/stdc++.h>
#define lili long long int
#define ld long double
using namespace std;

const int N = 5e4 + 5;
int a[N];
int n, cnt;

void bubbleSort() {
	for(int step = 1; step < n; step++) {
		for(int j = 0; j < n - step; j++) {
			if(a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				cnt++;
			}
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cnt = 0;
	bubbleSort();
	cout << "Array is sorted in " << cnt <<  " swaps.\n";
	cout << "First Element: " << a[0] << "\n";
	cout << "Last Element: " << a[n - 1] << "\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
    return 0;
}
