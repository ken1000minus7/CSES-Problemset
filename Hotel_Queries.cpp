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
    segtree[ind] = max(segtree[2 * ind + 1], segtree[2 * ind + 2]);
}

void update(vector<ll> &segtree, int l, int r, int ind, int i, ll x) {
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
    segtree[ind] = max(segtree[2 * ind + 1], segtree[2 * ind + 2]);
}

ll query(vector<ll> &segtree, int l, int r, int ind, int s, int e) {
    if(l > e || r < s) return 0;
    if(l >= s && r <= e) return segtree[ind];
    int mid = (r - l) / 2 + l;
    return max(query(segtree, l, mid, 2 * ind + 1, s, e), query(segtree, mid + 1, r, 2 * ind + 2, s, e));
}

int main()
{
    FIO
    int n, m;
    cin >> n >> m;
    vector<ll> h(n), r(m);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(int j = 0; j < m; j++) {
        cin >> r[j];
    }
    vector<ll> segtree(4 * n);
    buildTree(segtree, h, 0, n - 1, 0);
    for(int i = 0; i < m; i++) {
        int l = 0, rr = n - 1;
        ll val = -1;
        // cout << "lexgo " << i << "\n";
        while(l <= rr) {
            int mid = (rr - l) / 2 + l;
            ll maxi = query(segtree, 0, n - 1, 0, l, mid);
            if(maxi >= r[i]) {
                val = maxi;
                rr = mid - 1;
            }
            else {
                l = mid + 1;
            }
            // cout << l << " " << rr << "\n";
        }
        // cout << val << "\n";
        if(val == -1) l = -1;
        cout << l + 1 << " ";
        if(l >= 0) {
            update(segtree, 0, n - 1, 0, l, val - r[i]);
        }
    }
    cout << "\n";
    return 0;
}