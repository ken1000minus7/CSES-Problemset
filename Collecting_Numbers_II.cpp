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
    int n, m;
    cin >> n >> m;
    vector<int> inds(n + 2, -1);
    vector<int> arr(n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(inds[arr[i] - 1] == -1) ans++;
        inds[arr[i]] = i;
    }
    while(m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int o = max(l, r);
        l = min(l, r);
        r = o;
        swap(inds[arr[l]], inds[arr[r]]);
        swap(arr[l], arr[r]);

        if(arr[l] - 1 == arr[r]) {
            ans++;
        }
        else if(arr[l] == arr[r] - 1) {
            ans--;
        }
        
        if(inds[arr[l] - 1] != -1 && arr[l] - 1 != arr[r]) {
            if(inds[arr[l] - 1] < l && inds[arr[l] - 1] >= r) ans--;
            else if(inds[arr[l] - 1] < r && inds[arr[l] - 1] >= l) ans++;
        } 

        if(inds[arr[r] - 1] != -1 && arr[r] - 1 != arr[l]) {
            if(inds[arr[r] - 1] < r && inds[arr[r] - 1] >= l) ans--;
            else if(inds[arr[r] - 1] < l && inds[arr[r] - 1] >= r) ans++;
        }

        if(inds[arr[l] + 1] != -1 && inds[arr[l] + 1] != r) {
            if(inds[arr[l] + 1] > r && inds[arr[l] + 1] < l) ans++;
            else if(inds[arr[l] + 1] < r && inds[arr[l] + 1] > l) ans--;
        }
        if(inds[arr[r] + 1] != -1 && inds[arr[r] + 1] != l) {
            if(inds[arr[r] + 1] > l && inds[arr[r] + 1] < r) ans++;
            else if(inds[arr[r] + 1] < l && inds[arr[r] + 1] > r) ans--;
        }
        cout << ans << "\n";
    }
    return 0;
}