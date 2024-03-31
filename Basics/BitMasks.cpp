#include<bits/stdc++.h>
using namespace std;

//Generating all subsets
//Time complexity: O(n * 2 ^ n)
void generateAllSubsets() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                cout << a[i] << " ";
            }
        }
        cout << "\n";
    }
}


int main() {
    generateAllSubsets();
    return 0;
}