#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
using namespace std;

int main()
{
    FIO
    int n;
    cin>>n;
    if(n<=3 && n>1) {
            cout<<("NO SOLUTION\n");
        }
        else {
            cout<<(n/2 + 1) << " ";
            int i = 1;
            int j = n;
            while(i<j) {
                cout<<i << " ";
                if(j > i+1) cout<<j<< " ";
                i++;
                j--;
            }
        }
        cout<<"\n";
    return 0;
}