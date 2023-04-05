#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

pair<ll, ll> dostuff(int i, int j, vector<ll> &arr, vector<vector<pair<ll, ll>>> &dp) {
    if(j < i) return {0, 0};
    if(dp[i][j].first != -1) return dp[i][j];
    auto p1 = dostuff(i + 1, j, arr, dp);
    auto p2 = dostuff(i, j - 1, arr, dp);
    return dp[i][j] = {max(arr[i] + p1.second, arr[j] + p2.second), arr[i] + p1.second > arr[j] + p2.second ? p1.first : p2.first};
}

int main()
{
    FIO
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n, {-1, -1}));
    auto p = dostuff(0, n - 1, arr, dp);
    cout << p.first << "\n";
    return 0;
}