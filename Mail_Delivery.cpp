#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"IMPOSSIBLE\n";
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
int main()
{
    FIO
    // int t;
    // cin >> t;
    // while(t--) {
        int n, m;
        cin >> n >> m;
        vector<set<int>> adj(n, set<int>());
        vector<int> degree(n);
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[a].insert(b);
            adj[b].insert(a);
            degree[a]++;
            degree[b]++;
        }
 
        vector<int> done(n);
        function<void(int)> dfs;
        dfs = [&](int i) {
            done[i]++;
            for(int j : adj[i]) {
                if(done[j]) continue;
                dfs(j);
            }
        };
        dfs(0);
 
        bool op = true;
        for(int i = 0; i < n; i++) {
            if(degree[i] % 2 != 0 || !degree[0] || (degree[i] > 0 && !done[i])) {
                op = false;
                break;
            }
        }
        if(!op) {
            NO
            return 0;
        }
        vector<int> ans;
        // function<void(int)> dostuff;
        // dostuff = [&](int i) {
        //     // cout << i << " " << degree[i] << "\n";
        //     if(degree[i] == 0) {
        //         ans.push_back(i + 1);
        //     }
        //     else {
        //         for(int j = 0; j < n; j++) {
        //             if(!adj[i][j]) continue;
        //             degree[i]--;
        //             degree[j]--;
        //             adj[i][j]--;
        //             adj[j][i]--;
        //             dostuff(j);
        //         }
        //         ans.push_back(i + 1);
        //     }
        // };
        // dostuff(0);
 
        stack<int> s;
        s.push(0);
        int curr = 0;
        while(!s.empty()) {
            if(degree[curr] == 0) {
                ans.push_back(curr + 1);
                curr = s.top();
                s.pop();
            }
            else {
                int j = *adj[curr].begin();
                degree[curr]--;
                degree[j]--;
                adj[curr].erase(j);
                adj[j].erase(curr);
                s.push(curr);
                curr = j;
            }
        }
 
        reverse(all(ans));
        if(ans.size() != m + 1) {
            NO
            return 0;
        }
        for(int a : ans) cout << a << " ";
        cout << "\n";
    // }
    return 0;
}