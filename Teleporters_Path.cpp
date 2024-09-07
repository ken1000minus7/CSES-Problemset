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
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n, set<int>());
    vector<int> indegree(n), outdegree(n);
    for(int i =0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].insert(b);
        outdegree[a]++;
        indegree[b]++;
    }
    vector<int> done(n);
    auto dfs = [&](auto &&self, int i) -> void {
        done[i]++;
        for(int j : adj[i]) {
            if(done[j]) continue;
            self(self, j);
        }
    };
    dfs(dfs, 0);
    bool op = true;
    int i1 = -1, i2 = -1;
    for(int i = 0; i < n; i++) {
        if(!done[i] && (indegree[i] + outdegree[i]) > 0) {
            op = false;
            break;
        }
        if(indegree[i] == outdegree[i]) continue;
        if(i1 == -1 && outdegree[i] == indegree[i] + 1) i1 = i;
        else if(i2 == -1 && outdegree[i] + 1 == indegree[i]) i2 = i;
        else {
            op = false;
            break;
        }
    }
    if(!op || i1 == -1 || i2 == -1 || i1 != 0 || i2 != n - 1) {
        NO
        return 0;
    }
    // adj[i2].insert(i1);
    // indegree[i1]++;
    // outdegree[i2]++;
    stack<int> s;
    s.push(i1);
    vector<int> ans;
    int curr = i1;
    while(!s.empty()) {
        if(outdegree[curr] == 0) {
            ans.push_back(curr);
            curr = s.top();
            s.pop();
        }
        else {
            int j = *adj[curr].begin();
            indegree[j]--;
            outdegree[curr]--;
            adj[curr].erase(j);
            s.push(curr);
            curr = j;
        }
    }
    // vector<int> fans;
    // for(int i = 0; i < m + 1; i++) {
    //     if((ans[i] == i1 && ans[i + 1] == i2) || (ans[i] == i2 && ans[i + 1] == i1)) {
    //         for(int j = i + 1; j < m + 1; j++) fans.push_back(ans[j]);
    //         for(int j = 0; j <= i; j++) fans.push_back(ans[j]);
    //         break;
    //     }
    // }
    // if(fans[0] == i2) reverse(all(fans));
    // for(int a : ans) cout << a + 1 << " ";
    // cout << "\n";
    reverse(all(ans));
    for(int a : ans) cout << a + 1 << " ";
    cout << "\n";
    return 0;
}