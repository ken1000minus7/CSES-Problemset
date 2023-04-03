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
    ll x;
    cin >> n >> x;
    map<ll, int> done;
    bool found = false;
    for(int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if(done.count(x - a)) {
            cout << done[x - a] + 1 << " " << i + 1 << "\n";
            found = true;
            break;
        }
        done[a] = i;
    }
    if(!found) {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}