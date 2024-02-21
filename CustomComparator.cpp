#include<bits/stdc++.h>
#define lili long long int
using namespace std;

//default
bool cmp1(pair<int, int> x, pair<int, int> y) {
    return x < y;
}

//Sort by first elements. If equal, sort by descending order of second elements
bool cmp2(pair<int, int> x, pair<int, int> y) {
    if(x.first == y.first) {
        return x.second > y.second;
    }
    return x.first < y.first;
}

//Sort in descending order
bool cmp3(pair<int, int> x, pair<int, int> y) {
    return x > y;
}

// Sort by second: https://vjudge.net/solution/49200100/9XKnvrwsYjt4aJ8lvekn

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> v = {{1, 1}, {1, 2}, {1, 2}, {2, 2}, {3, 2}, {3, 5}, {5, 5}};

    cout << "Default:\n";
    sort(v.begin(), v.end(), cmp1);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    /*
    1 1
    1 2
    1 2
    2 2
    3 2
    3 5
    5 5
    */

    cout << "Sort by descending order of second elements if first elements are equal:\n";
    sort(v.begin(), v.end(), cmp2);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    /*
    1 2
    1 2
    1 1
    2 2
    3 5
    3 2
    5 5
    */

    cout << "Sort in descending order:\n";
    sort(v.begin(), v.end(), cmp3);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    /*
    5 5
    3 5
    3 2
    2 2
    1 2
    1 2
    1 1
    */
    return 0;
}
