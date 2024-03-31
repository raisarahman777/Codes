#include<bits/stdc++.h>
using namespace std;

void primeFactorize(int n) {
	vector<int> prime_factors;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			while(n % i == 0) {
				prime_factors.push_back(i);
				n /= i;
			}
		}
	}
	if(n > 1) {
		prime_factors.push_back(n);
	}
	for(auto x : prime_factors) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
	int n;
	while(cin >> n) {
		primeFactorize(n);
	}
}
