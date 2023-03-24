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
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    vector<ll> prefsum(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        prefsum[i] = arr[i] ^ (i > 0 ? prefsum[i - 1] : 0);
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << (prefsum[r] ^ prefsum[l] ^ arr[l]) << "\n";
    }
    return 0;
}