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
    int s = sqrt(n);
    if(s * s != n) s++;
    vector<ll> b(s);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        b[i / s] += arr[i];
    }
    vector<ll> upd(n);
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int l, r;
            ll x;
            cin >> l >> r >> x;
            l--, r--;
            while(l <= r) {
                if(l % s == 0 && l + s - 1 <= r) {
                    upd[l / s] += x;
                    l += s;
                }
                else {
                    arr[l] += x;
                    l++;
                }
            }
        }
        else {
            int i;
            cin >> i;
            i--;
            cout << (arr[i] + upd[i / s]) << "\n";
        }
    }
    return 0;
}