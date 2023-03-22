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
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    int i = 0, j = n - 1;
    int ans = 0;
    while(i <= j) {
        if(arr[i] + arr[j] <= x) {
            i++;
        }
        ans++;
        j--;
    }
    cout << ans << '\n';
    return 0;
}