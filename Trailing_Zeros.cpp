#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

int main()
{
    FIO
    ll n;
    cin>>n;
    ll ans = 0;
    ll temp = 5;
    while(n/temp > 0)
    {
        ans += n/temp;
        temp *=5;
    }
    cout<<ans<<"\n";
    return 0;
}