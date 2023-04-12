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
    int n;
    cin >> n;
    ll x;
    cin >> x;
    unordered_map<ll, int> freq;
    int ans = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        sum += a;
        ans += freq[sum - x];
        freq[sum]++;
        if(sum == x) ans++;
    }
    cout << ans << "\n";
    return 0;
}