#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

int dostuff(int i, int j, vector<vector<int>> &dp) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(dp[j][i] != -1) return dp[j][i];
    if(i == 1) return j - 1;
    if(j == 1) return i - 1;
    int ans = 1000000;
    for(int ii = 1; ii < i; ii++) {
        ans = min(ans, 1 + dostuff(ii, j, dp) + dostuff(i - ii, j, dp));
    }
    for(int jj = 1; jj < j; jj++) {
        ans = min(ans, 1 + dostuff(i, jj, dp) + dostuff(i, j - jj, dp));
    }
    return dp[i][j] = ans;
}

int main()
{
    FIO
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(max(a, b) + 1, vector<int>(max(a, b) + 1, -1));
    cout << dostuff(a, b, dp) << "\n";
    return 0;
}