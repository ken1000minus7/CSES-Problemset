#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

int dostuff(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if(i == s1.length()) return s2.length() - j;
    if(j == s2.length()) return s1.length() - i;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]) {
        return dp[i][j] = dostuff(i + 1, j + 1, s1, s2, dp);
    }
    else {
        return dp[i][j] = 1 + min({
            dostuff(i, j + 1, s1, s2, dp),
            dostuff(i + 1, j, s1, s2, dp),
            dostuff(i + 1, j + 1, s1, s2, dp)
        });
    }
}

int main()
{
    FIO
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    cout << dostuff(0, 0, s1, s2, dp) << "\n";
    return 0;
}