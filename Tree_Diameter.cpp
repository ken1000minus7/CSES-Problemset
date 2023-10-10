#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

int dostuff(int i, int parent, vector<vector<int>> &adj, int &ans) {
    multiset<int> s;
    for(int j: adj[i]) {
        if(j == parent) continue;
        s.insert(-dostuff(j, i, adj, ans));
    }
    if(s.empty()) return 0;
    int maxi1 = -*s.begin();
    int maxi2 = s.size() > 1 ? -*next(s.begin()) : 0;
    ans = max(ans, maxi1 + maxi2 + 1 + (s.size() > 1));
    return max(maxi1, maxi2) + 1;
}
                                                        
int main()
{
    FIO
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    dostuff(0, -1, adj, ans);
    cout << ans << "\n";
    return 0;
}