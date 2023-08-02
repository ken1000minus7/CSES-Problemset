#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

void dostuff(int i, ll sum, ll &x, vector<ll> &arr, vector<ll> &sums) {
    if(sum > x) return;
    if(i >= arr.size()) {
        sums.push_back(sum);
        return;
    }
    dostuff(i + 1, sum + arr[i], x, arr, sums);
    dostuff(i + 1, sum, x, arr, sums);
}

int main()
{
    FIO
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll> arr(n);
    vector<ll> left, right;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i < n / 2) left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }   
    vector<ll> lsums, rsums;
    dostuff(0, 0, x, left, lsums);
    dostuff(0, 0, x, right, rsums);
    sort(all(lsums));
    sort(all(rsums));
    ll ans = 0;
    for(int i = 0; i < lsums.size(); i++) {
        int i1 = lower_bound(all(rsums), x - lsums[i]) - rsums.begin();
        int i2 = upper_bound(all(rsums), x - lsums[i]) - rsums.begin();
        ans += i2 - i1;
    }
    cout << ans << "\n";
    return 0;   
}