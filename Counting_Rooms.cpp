#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

void dfs(int i, int j, vector<string> &arr, vector<vector<int>> &done) {
    if(i >= arr.size() || i < 0 || j >= arr[0].length() || j < 0 || arr[i][j] == '#' || done[i][j]) return;
    done[i][j]++;
    dfs(i + 1, j, arr, done);
    dfs(i - 1, j, arr, done);
    dfs(i, j + 1, arr, done);
    dfs(i, j - 1, arr, done);
}

int main()
{
    FIO
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> done(n, vector<int>(m));
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!done[i][j] && arr[i][j] == '.') {
                ans++;
                dfs(i, j, arr, done);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}