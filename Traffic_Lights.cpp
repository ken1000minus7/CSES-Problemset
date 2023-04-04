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
    ll x;
    int n;
    cin >> x >> n;
    set<ll> s;
    s.insert(0);
    s.insert(x);
    multiset<ll> maxis;
    maxis.insert(-x);
    for(int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        auto fit = s.upper_bound(a);
        auto bit = prev(fit);
        ll curr = *fit - *bit;
        ll lnew = a - *bit;
        ll rnew = *fit - a;
        // cout << curr << " " << lnew << " " << rnew << "\n";
        auto it = maxis.find(-curr);
        if(it != maxis.end()) maxis.erase(it);
        maxis.insert(-lnew);
        maxis.insert(-rnew);
        s.insert(a);
        cout << -*maxis.begin() << " ";
    }
    cout << "\n";
    return 0;
}