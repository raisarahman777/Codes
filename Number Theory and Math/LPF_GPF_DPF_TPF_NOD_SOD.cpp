#include<bits/stdc++.h>
#define lili long long int
using namespace std;

const int N = 1e6 + 2;
int spf[N];
int gpf[N];

void sieve() {
	for(int i = 2; i < N; i++) {
		spf[i] = i;
		gpf[i] = i;
	}
	for(int i = 2; (lili)i * i < N; i++) {
		if(spf[i] == i) {
			for(lili j = 2 * i; j < N; j += i) {
				spf[j] = min(spf[j], i);
				if(gpf[j] == j) {
					gpf[j] = i;
				}
				else {
					gpf[j] = max(gpf[j], i);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
	sieve();
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		int num;
		cin >> num;
		int SPF = spf[num], GPF = gpf[num], DPF = 0, TPF = 0;
		lili NOD = 1, SOD = 1;
		while(num > 1) {
			int div = spf[num];
			int cnt = 0;
			DPF++;
			while(num % div == 0) {
				TPF++;
				cnt++;
				num /= div;
			}
			NOD *= (cnt + 1);
			SOD *= (pow(div, (cnt + 1)) - 1) / (div - 1);
		}
		if(num > 1) {
			NOD *= 2;
			SOD *= (num + 1);
		}
		cout << SPF << " " << GPF << " " << DPF << " " << TPF << " " << NOD << " " << SOD << "\n";
	}
}
