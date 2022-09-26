#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

ll mod = 1000000007;

ll mypow(ll a,ll r)
{
    if(r==0) return 1LL;
    if(r%2==0) return mypow(((a%mod)*(a%mod))%mod,r/2)%mod;
    return ((mypow(((a%mod)*(a%mod))%mod,r/2)%mod)*(a%mod))%mod;
}

int main()
{
    FIO
    ll n;
    cin>>n;
    cout<<mypow(2LL,n)<<"\n";
    return 0;
}