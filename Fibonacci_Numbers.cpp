#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

ll mod = 1000000007;

vector<vector<ll>> matmul(vector<vector<ll>> a, vector<vector<ll>> b) {
    vector<vector<ll>> ans;
    for(int i = 0; i < a.size(); i++) {
        vector<ll> temp;

        for(int j = 0; j < b[0].size(); j++) {
            ll val = 0;
            for(int k = 0; k < b.size(); k++) {
                val = (val + (a[i][k] * b[k][j]) % mod) % mod;
            }
            temp.push_back(val);
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<ll>> exp(vector<vector<ll>> a, ll b) {
    if(b == 1) return a;
    if(b % 2 == 0) return exp(matmul(a, a), b / 2);
    return matmul(a, exp(a, b - 1));
}

int main()
{
    FIO
    ll n;
    cin >> n;
    if(n <= 1) {
        cout << n << "\n";
        return 0;
    }
    vector<vector<ll>> a = {{1},{0}};
    vector<vector<ll>> t = {{1, 1}, {1, 0}}; 
    vector<vector<ll>> ans = matmul(exp(t, n - 1), a);
    cout << ans[0][0] << "\n";
    // cout << ans[1][0] << " " << ans[1][1] << "\n";
    return 0;
}