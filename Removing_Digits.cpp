#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;

int main()
{
    FIO
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT32_MAX);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int a = i;
        while(a > 0) {
            int j = a % 10;
            a /= 10;
            if(j == 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - j]);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}