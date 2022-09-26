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
    cout<<0<<"\n";
    ll temp = 0;
    ll add = 8;
    for(ll i=2;i<=n;i++)
    {
        ll j = i*i;
        cout<<((j*(j-1))/2 - temp) << "\n";
        temp += add;
        add += 8;
    }
    return 0;
}