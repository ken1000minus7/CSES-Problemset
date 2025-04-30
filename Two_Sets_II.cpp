#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;

ll mod = 1000000007;

ll power(ll a, ll e) {
    if(e == 0) return 1;
    if(e == 1) return a;
    if(e % 2 == 0) return power((a * a) % mod, e / 2) % mod;
    return (a * power(a, e - 1)) % mod;
}

int main()
{
    FIO
    ll n;
    cin >> n;
    ll sum = (n * (n + 1)) / 2;
    if(sum % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }
    ll req = sum / 2;
    vector<ll> dp(req + 1);
    dp[0] = 1;
    for(ll i = n; i >= 1; i--) {
        vector<ll> ndp(req + 1);

        for(ll j = req; j >= 0; j--) {
            ndp[j] = dp[j];
            if(j - i >= 0) {
                ndp[j] = (ndp[j] + dp[j - i]) % mod;
            }
        }
        dp = ndp;
    }
    cout << (dp[req] * power(2, mod - 2)) % mod << "\n";
    return 0;
}