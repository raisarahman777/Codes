/*
Problem: SOPJ - BUGLIFE
Simplified problem statement:
Bugs only interact with opposite gender. Given the number of bugs and interactions between them, find if there are any suspicious species.
*/


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 2005;
vector<int> adj[N];
bool vis[N];
int gender[N];
int n, m;
bool suspicious;

void dfs(int s, int g) {
    gender[s] = g;
    for (int i = 0; i < adj[s].size(); i++) {
        if (gender[adj[s][i]] == -1) {
            dfs(adj[s][i], 1 - g); //assign the opposite gender
        }
        else if (gender[adj[s][i]] == g) {
            suspicious = true;
            return;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        gender[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    suspicious = false;
    for (int i = 1; i <= n; i++) {
        if (gender[i] == -1) {
            dfs(i, 0);
        }
    }
    if (suspicious) {
        cout << "Suspicious bugs found!\n";
        return;
    }
    cout << "No suspicious bugs found!\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    int tc = 1;
    while(t--) {
        cout << "Scenario #" << tc++ << ":\n";
        solve();
    }
    return 0;
}
