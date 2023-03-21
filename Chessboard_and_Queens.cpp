#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

bool isSafe(int i, int j, vector<int> &cols, vector<string> &chess) {
    if(cols[j] != -1 || chess[i][j] == '*') return false;
    for(int k = 0; k < 8; k++) {
        if(cols[k] != -1 && abs(cols[k] - i) == abs(k - j)) return false;
    }
    return true;
}

void nqueen(int i, vector<int> &cols, vector<string> &chess, int &ans) {
    if(i >= 8) {
        ans++;
        return;
    }
    for(int j = 0; j < 8; j++) {
        if(isSafe(i, j, cols, chess)) {
            cols[j] = i;
            nqueen(i + 1, cols, chess, ans);
            cols[j] = -1;
        }
    }
}

int main()
{
    FIO
    vector<string> chess(8);
    for(int i = 0; i < 8; i++) {
        cin >> chess[i];
    }
    vector<int> cols(8, -1);
    int ans = 0;
    nqueen(0, cols, chess, ans);
    cout << ans << "\n";
    return 0;
}