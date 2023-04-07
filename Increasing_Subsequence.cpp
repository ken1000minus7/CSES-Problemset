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
    cin >> n;
    vector<ll> arr(n);
    vector<ll> temp;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        int ind = lower_bound(all(temp), arr[i]) - temp.begin();
        if(ind >= temp.size()) temp.push_back(arr[i]);
        else temp[ind] = arr[i];
    }
    cout << temp.size() << "\n";
    return 0;
}