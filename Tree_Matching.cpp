#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

int dostuff(int i, int parent, vector<vector<int>> &adj, bool cansel, vector<vector<int>> &dp) {
    if(i >= adj.size()) return 0;
    if(dp[i][cansel] != -1) return dp[i][cansel];
    int sumi = 0;
    for(int j: adj[i]) {
        if(j == parent) continue;
        sumi += max(dostuff(j, i, adj, true, dp), dostuff(j, i, adj, false, dp));
    }
    if(cansel) {
        int ans = 0;
        for(int j: adj[i]) {
            if(j == parent) continue;
            int csel = dostuff(j, i, adj, true, dp);
            int cnsel = dostuff(j, i, adj ,false, dp);
            ans = max(ans, 1 + sumi - max(csel, cnsel) + cnsel);
        }
        return dp[i][cansel] = ans;
    }
    else {
        return dp[i][cansel] = sumi;
    }
}

int main()
{
    FIO
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> dp(n, vector<int>(2, -1));
    int csel = dostuff(0, -1, adj, true, dp);
    int cnsel = dostuff(0, -1, adj, false, dp);
    cout << max(csel, cnsel) << "\n";
    return 0;
}