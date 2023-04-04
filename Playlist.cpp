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
    set<ll> done;
    int c = 0;
    int ans = 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(done.count(arr[i])) {
            // cout << "lol\n";
            ans = max(ans, c);
            while(j <= i) {
                done.erase(arr[j]);
                j++;
                c--;
                if(arr[j - 1] == arr[i]) break;
            }
        }
        done.insert(arr[i]);
        c++;
        // cout << arr[i] << " " << c << "\n";
    }
    ans = max(ans, c);
    cout << ans << "\n";
    return 0;
}