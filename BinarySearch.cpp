#include<iostream>
using namespace std;

int n = 14;
int arr[] = {5, 9, 10, 10, 10, 14, 17, 17, 20, 22, 22, 22, 22, 29};

int firstIndex(int first, int last, int x) {
    int lo = first, hi = last, mid;
    while(lo < hi) {
        mid = (lo + hi) / 2;
        if(arr[mid] < x) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if(arr[lo] == x) {
        return lo;
    }
    return -1;
}

// int firstIndex(int first, int last, int x) {
//     int lo = first, hi = last, mid, ans = -1;
//     while(lo <= hi) {
//         mid = (lo + hi) / 2;
//         if(arr[mid] == x) {
//             ans = mid;
//         }
//         if(arr[mid] < x) {
//             lo = mid + 1;
//         }
//         else {
//             hi = mid - 1;
//         }
//     }
//     return ans;
// }

int lastIndex(int first, int last, int x) {
    int lo = first, hi = last, mid;
    while(lo < hi) {
        mid = (lo + hi + 1) / 2;
        if(arr[mid] > x) {
            hi = mid - 1;
        }
        else {
            lo = mid;
        }
    }
    if(arr[lo] == x) {
        return lo;
    }
    return -1;
}

// int lastIndex(int first, int last, int x) {
//     int lo = first, hi = last, mid, ans = -1;
//     while(lo <= hi) {
//         mid = (lo + hi) / 2;
//         if(arr[mid] == x) {
//             ans = mid;
//         }
//         if(arr[mid] > x) {
//             hi = mid - 1;
//         }
//         else {
//             lo = mid + 1;
//         }
//     }
//     return ans;
// }

int greaterThan(int first, int last, int x) {
    if(arr[last] <= x) {
        return -1;
    }
    int lo = first, hi = last, mid;
    while(lo < hi) {
        mid = (lo + hi) / 2;
        if(arr[mid] <= x) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    return lo;
}

// int greaterThan(int first, int last, int x) {
//     int lo = first, hi = last, mid, ans = -1;
//     while(lo <= hi) {
//         mid = (lo + hi) / 2;
//         if(arr[mid] <= x) {
//             lo = mid + 1;
//         }
//         else {
//             hi = mid - 1;
//             ans = mid;
//         }
//     }
//     return ans;
// }

int greaterThanOrEqualTo(int first, int last, int x) {
    if(arr[last] < x) {
        return -1;
    }
    int lo = first, hi = last, mid;
    while(lo < hi) {
        mid = (lo + hi) / 2;
        if(arr[mid] < x) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    return lo;
}

// int greaterThanOrEqualTo(int first, int last, int x) {
//     int lo = first, hi = last, mid, ans = -1;
//     while(lo <= hi) {
//         mid = (lo + hi) / 2;
//         if(arr[mid] < x) {
//             lo = mid + 1;
//         }
//         else {
//             hi = mid - 1;
//             ans = mid;
//         }
//     }
//     return ans;
// }

int main() {
    int x;
    while(cin >> x) {
        cout << greaterThanOrEqualTo(0, n - 1, x) << endl;
    }
}
