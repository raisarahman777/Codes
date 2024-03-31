#include<bits/stdc++.h>
#define lili long long int
using namespace std;

lili noOfDivisors(lili n) {
	lili NOD = 1;
	for(int i = 2; i * i <= n; i++) {
		int x = 0;
		while(n % i == 0) {
			x++;
			n /= i;
		}
		NOD *= (x + 1);
	}
	if(n > 1) {
		NOD *= 2;
	}
	return NOD;
}

int main() {
  lili n;
  while(cin >> n) {
  	cout << noOfDivisors(n) << endl;
  }
}
