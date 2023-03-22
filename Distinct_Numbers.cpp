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
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int c = 0;
    sort(all(arr));
    for(int i = 0; i < n; i++) {
        if(i == n - 1 || arr[i] != arr[i + 1]) {
            c++;
        }
    }
    cout << c << "\n";
    return 0;
}