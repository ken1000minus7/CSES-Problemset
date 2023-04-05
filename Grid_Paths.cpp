#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;
const ll mod = 1000000007;

ll dostuff(int i, int j, vector<string> &grid, vector<vector<ll>> &dp) {
    int n = grid.size();
    if(i >= n || i < 0 || j >= n || j < 0 || grid[i][j] == '*') return 0;
    if(i == n - 1 && j == n - 1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = (dostuff(i + 1, j, grid, dp) + dostuff(i, j + 1, grid, dp)) % mod;
}

int main()
{
    FIO
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    cout << dostuff(0, 0, grid, dp) << "\n";
    return 0;
}