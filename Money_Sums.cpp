#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

set<ll> dostuff(int i, vector<ll> &arr, vector<set<ll>> &dp) {
    if(i >= arr.size()) return set<ll>();
    if(dp[i].size() > 0) return dp[i];
    set<ll> ans;
    ans.insert(arr[i]);
    set<ll> next = dostuff(i + 1, arr, dp);
    ans.insert(all(next));
    for(auto a : next) {
        ans.insert(a + arr[i]);
    }
    return dp[i] = ans;
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
    vector<set<ll>> dp(n, set<ll>());
    set<ll> ans = dostuff(0, arr, dp);
    cout << ans.size() << "\n";
    for(auto a : ans) {
        cout << a << " ";
    }
    cout << "\n";
    return 0;
}