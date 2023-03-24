#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

int conv(char c) {
    if(c == '*') return 1;
    return 0;
}

int main()
{
    FIO
    int n, q;
    cin >> n >> q;
    vector<string> forest(n);
    vector<vector<int>> prefsum(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        cin >> forest[i];
        for(int j = 0; j < n; j++) {
            prefsum[i][j] = (j > 0 ? prefsum[i][j - 1] : 0) + (i > 0 ? prefsum[i - 1][j] : 0) - (i > 0 && j > 0 ? prefsum[i - 1][j - 1] : 0) + conv(forest[i][j]);
        }
    }
    while(q--) {
        int iu, ju, id, jd;
        cin >> iu >> ju >> id >> jd;
        iu--, ju--, id--, jd--;
        int ans = prefsum[id][jd] - (ju > 0 ? prefsum[id][ju - 1] : 0) - (iu > 0 ? prefsum[iu - 1][jd] : 0) + (iu > 0 && ju > 0 ? prefsum[iu - 1][ju - 1] : 0);
        cout << ans << "\n";
    }
    return 0;
}