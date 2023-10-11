#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

int main()
{
    FIO
    int n, m;
    cin >> n >> m;
    vector<ll> dp(m + 1);
    vector<ll> pr(n), pg(n);
    for(int i = 0; i < n; i++) {
        cin >> pr[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> pg[i];
    }
    for(int i = n - 1; i >= 0; i--) {
        vector<ll> ndp(m + 1);
        for(int j = 1; j <= m; j++) {
            ndp[j] = dp[j];
            if(pr[i] <= j) {
                ndp[j] = max(ndp[j], pg[i] + dp[j - pr[i]]);
            }
        }
        dp = ndp;
    }
    cout << dp[m] << "\n";
    return 0;
}