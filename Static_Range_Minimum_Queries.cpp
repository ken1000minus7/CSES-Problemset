#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

int find(int i, vector<int> &parent) {
    if(parent[i] == -1) return i;
    return parent[i] = find(parent[i], parent);
}

void unify(int i, int j, vector<int> &parent, vector<int> &rank) {
    i = find(i, parent);
    j = find(j, parent);
    if(i == j) return;
    if(rank[i] >= rank[j]) {
        parent[j] = i;
        if(rank[i] == rank[j]) rank[i]++;
    }
    else {
        parent[i] = j;
    }
}

int main()
{
    FIO
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> que;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        que.push_back({r, l, i});
    }
    sort(all(que));
    int j = 0;
    stack<int> s;
    vector<int> parent(n, -1), rank(n);
    vector<int> ans(q);
    for(int i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()] > arr[i]) {
            parent[s.top()] = i;
            s.pop();
        }
        s.push(i);
        while(j < q && que[j][0] == i) {
            ans[que[j][2]] = arr[find(que[j][1], parent)];
            j++;
        }
    }
    for(int a : ans) {
        cout << a << "\n";
    }
    return 0;
}