#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

ll dostuff(int i, vector<vector<ll>> &arr, vector<ll> &dp) {
    if(i >= arr.size()) return 0;
    if(dp[i] != -1) return dp[i];
    vector<ll> search = {arr[i][1], INT32_MAX, INT32_MAX};
    int nind = upper_bound(all(arr), search) - arr.begin();
    return dp[i] = max(dostuff(i + 1, arr, dp), arr[i][2] + dostuff(nind, arr, dp));
}

int main()
{
    FIO
    int n;
    cin >> n;
    vector<vector<ll>> arr;
    for(int i = 0; i < n; i++) {
        ll a, b, p;
        cin >> a >> b >> p;
        arr.push_back({a, b, p});
    }
    sort(all(arr));
    vector<ll> dp(n, -1);
    cout << dostuff(0, arr, dp) << "\n";
    return 0;
}