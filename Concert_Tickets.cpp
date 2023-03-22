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
    int n, m;
    cin >> n >> m;
    multiset<ll> s;
    for(int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        s.insert(a);
    }
    for(int i = 0; i < m; i++) {
        ll req;
        cin >> req;
        auto lb = s.lower_bound(req);
        if(s.empty() || (lb == s.begin() && *lb != req)) {
            cout << -1 << "\n";
            continue;
        }
        if(*lb == req) {
            cout << req << "\n";
            s.erase(lb);
        }
        else {
            cout << *prev(lb) << "\n";
            s.erase(prev(lb));
        }
    }
    return 0;
}