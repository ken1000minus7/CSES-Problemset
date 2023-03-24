#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

void buildTree(vector<ll> &segtree, vector<ll> &arr, int l, int r, int ind) {
    if(l == r) {
        segtree[ind] = arr[l];
        return;
    }
    int mid = (r - l) / 2 + l;
    buildTree(segtree, arr, l, mid, 2 * ind + 1);
    buildTree(segtree, arr, mid + 1, r, 2 * ind + 2);
    segtree[ind] = min(segtree[2 * ind + 1], segtree[2 * ind + 2]);
}

void update(vector<ll> &segtree, int l, int r, int ind, int &i, ll &x) {
    if(l == r) {
        segtree[ind] = x;
        return;
    }
    int mid = (r - l) / 2 + l;
    if(i <= mid) {
        update(segtree, l, mid, 2 * ind + 1, i, x);
    }
    else {
        update(segtree, mid + 1, r, 2 * ind + 2, i, x);
    }
    segtree[ind] = min(segtree[2 * ind + 1], segtree[2 * ind + 2]);
}

ll query(vector<ll> &segtree, int l, int r, int ind, int s, int e) {
    if(l > e || r < s) return INT32_MAX;
    if(l >= s && r <= e) return segtree[ind];
    int mid = (r - l) / 2 + l;
    return min(query(segtree, l, mid, 2 * ind + 1, s, e), query(segtree, mid + 1, r, 2 * ind + 2, s, e));
}

int main()
{
    FIO
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    vector<ll> segtree(4 * n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    buildTree(segtree, arr, 0, n - 1, 0);
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int k;
            ll u;
            cin >> k >> u;
            k--;
            update(segtree, 0, n - 1, 0, k, u);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(segtree, 0, n - 1, 0, l, r) << "\n";
        }
    }
    return 0;
}