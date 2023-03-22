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
    vector<ll> start(n), end(n);
    for(int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        start[i] = l;
        end[i] = r;
    }
    sort(all(start));
    sort(all(end));
    int j = 0; 
    int ans = 0;
    int c = 0;
    for(int i = 0; i < n; i++) {
        while(end[j] < start[i]) {
            j++;
            c--;
        }
        c++;
        ans = max(ans, c);
    }
    cout << ans << '\n';
    return 0;
}