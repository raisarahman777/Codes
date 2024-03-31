#include<bits/stdc++.h>
#define lili long long int
using namespace std;

lili sumOfDivisors(lili n) {
	lili sum = 1;
	for(int i = 2; i * i <= n; i++) {
		int x = 0;
		while(n % i == 0) {
			x++;
			n /= i;
		}
		sum *= (pow(i, (x + 1)) - 1) / (i - 1);
	}
	if(n > 1) {
		sum *= (1 + n);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
	lili n;
	while(cin >> n) {
		cout << sumOfDivisors(n) << endl;
	}
}
