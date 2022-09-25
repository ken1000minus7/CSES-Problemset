#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

int main()
{
    FIO
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin >> y >> x;
        ll maxi = max(y,x);
        if(maxi==y) 
        {
            if(maxi%2==0)
            {
                cout<< (maxi*maxi - x + 1) << "\n";
            }
            else 
            {
                cout << ((maxi-1)*(maxi-1) + x) << "\n";
            }
        }
        else 
        {
            if(maxi%2!=0)
            {
                cout<< (maxi*maxi - y + 1) << "\n";
            }
            else 
            {
                cout << ((maxi-1)*(maxi-1) + y) << "\n";
            }
        }
    }
    return 0;
}