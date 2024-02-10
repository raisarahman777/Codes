#include<bits/stdc++.h>
#define lili long long int
using namespace std;

const int N = 1e6 + 2;
int spf[N];

void sieve() {
	for (int i = 2; i < N; i++) {
		if (i % 2) spf[i] = i;
		else spf[i] = 2;
	}
	for (int i = 3; (lili)i * i < N; i+= 2) {
		if (spf[i] == i) {
			for (lili j = i * i; j < N; j += i) {
				spf[j] = min(spf[j], i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
	sieve();
	for (int i = 2; i <= 100; i++) {
		cout << i << " " << spf[i] << endl;
	}
}
