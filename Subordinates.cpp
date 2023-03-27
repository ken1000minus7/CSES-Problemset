#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

int dfs(int i, vector<vector<int>> &adj, vector<int> &sub) {
    if(sub[i] != -1) return sub[i];
    sub[i] = 0;
    for(int j : adj[i]) {
        sub[i] += dfs(j, adj, sub) + 1;
    }
    return sub[i];
}

int main()
{
    FIO
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    vector<int> sub(n, -1);
    for(int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;
        adj[a].push_back(i);
    }
    dfs(0, adj, sub);
    for(int a : sub) {
        cout << a << " ";
    }
    cout << "\n";
    return 0;
}