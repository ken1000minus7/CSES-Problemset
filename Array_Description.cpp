#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

ll mod = 1000000007;

ll dostuff(int i, int p, vector<ll> &arr, vector<vector<ll>> &dp) {
    if(i >= arr.size()) return 1;
    if(dp[i][p] != -1) return dp[i][p];
    if(arr[i] > 0) {
        if(p == 0 || abs(p - arr[i]) <= 1) {
            return dp[i][p] = dostuff(i + 1, arr[i], arr, dp);
        }
        else {
            return dp[i][p] = 0;
        }
    }
    else {
        ll m = dp[0].size() - 1;
        if(p == 0) {
            ll ans = 0;
            for(int j = 1; j <= m; j++) {
                ans = (ans + dostuff(i + 1, j, arr, dp)) % mod;
            }
            return dp[i][p] = ans;
        }
        else {
            ll ans = dostuff(i + 1, p, arr, dp);
            if(p > 1) {
                ans = (ans + dostuff(i + 1, p - 1, arr, dp)) % mod;
            }
            if(p < m) {
                ans = (ans + dostuff(i + 1, p + 1, arr, dp)) % mod;
            }
            return dp[i][p] = ans;
        }
    }
}

int main()
{
    FIO
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll>(m + 1, -1));
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << dostuff(0, 0, arr, dp) << "\n";
    return 0;
}