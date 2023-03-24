#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;
const ll mod = 1000000007;

int main()
{
    FIO
    int n, x;
    cin >> n >> x;
    vector<ll> dp(x + 1);
    vector<ll> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < coins.size(); j++) {
            if(i - coins[j] >= 0) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
            }
        }
    }
    cout << dp[x] << "\n";
    return 0;
}