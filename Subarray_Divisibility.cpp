#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"-1\n";
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
 
int main()
{
    FIO
    int n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    unordered_map<ll, ll> freq;
    ll ans = 0;
    ll add = ((1000000000 + n - 1) / n) * n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] += add; 
        arr[i] %= n;
        sum = (sum + arr[i]) % n;
        ans += freq[sum];
        freq[sum]++;
        if(sum == 0) ans++;
    }
    // for(ll a : arr) cout << a << " ";
    // cout << "\n";
    cout << ans << "\n";
    return 0;
}