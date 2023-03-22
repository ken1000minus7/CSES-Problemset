#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

ll ways(int n, vector<ll> &dp, vector<int> &coins) {
    if(n < 0) return INT32_MAX;
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    dp[n] = INT32_MAX - 1;
    for(int i = 0; i < coins.size(); i++) {
        dp[n] = min(dp[n], ways(n - coins[i], dp, coins));
    }
    dp[n]++;
    return dp[n];
}

int main()
{
    FIO
    int n, x;
    cin >> n >> x;
    vector<ll> dp(x + 1, -1);
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    ll ans = ways(x, dp, coins);
    if(ans == INT32_MAX) cout << -1 << '\n';
    else cout << ans << "\n";
    return 0;
}