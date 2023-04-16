#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;
const ll mod = 1000000007;

ll expp(ll a, ll b) {
    if(b == 0) return 1;
    if(b % 2 == 0) {
        return expp((a * a) % mod, b / 2);
    }
    else {
        return (a * expp(a, b - 1)) % mod;
    }
}

int main()
{
    FIO
    int t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        cout << expp(a, b) << "\n";
    }
    return 0;
}