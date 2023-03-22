#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;
ll mod = 1000000007;

ll ways(int n, vector<ll> &dp) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = 0;
    for(int i = 1; i <= 6; i++) {
        dp[n] = (dp[n] + ways(n - i, dp)) % mod;
    }
    return dp[n];
}

int main()
{
    FIO
    int n;
    cin >> n;
    vector<ll> dp(n + 1, -1);
    cout << ways(n, dp) << "\n";
    return 0;
}