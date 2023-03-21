#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

void dostuff(int i, vector<ll> &arr, ll left, ll right, ll &ans) {
    if(i >= arr.size()) {
        ans = min(ans, abs(left - right));
        return;
    }
    dostuff(i + 1, arr, left + arr[i], right, ans);
    dostuff(i + 1, arr, left, right + arr[i], ans);
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
    ll ans = INT32_MAX;
    dostuff(0, arr, 0, 0, ans);
    cout << ans << '\n';
    return 0;
}