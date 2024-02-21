#include<bits/stdc++.h>
#define lili long long int
using namespace std;

void merge(int* a, int left, int mid, int right) {
    int left_pointer = left, right_pointer = mid + 1;
    int temp[right - left + 2];
    int i = 1;
    while (left_pointer <= mid && right_pointer <= right) {
        if (a[left_pointer] < a[right_pointer]) {
            temp[i++] = a[left_pointer++];
        }
        else {
            temp[i++] = a[right_pointer++];
        }
    }
    while (left_pointer <= mid) {
        temp[i++] = a[left_pointer++];
    }
    while (right_pointer <= right) {
        temp[i++] = a[right_pointer++];
    }
    i = 1;
    for (int j = left; j <= right; j++) {
        a[j] = temp[i++];
    }
}

void mergeSort(int* a, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    mergeSort(a, 1, n);

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}