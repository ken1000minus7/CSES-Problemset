#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

void hanoi(int n, int src, int dest, int aux, vector<pair<int, int>> &moves) {
    if(n == 0) return;
    hanoi(n - 1, src, aux, dest, moves);
    moves.push_back({src, dest});
    hanoi(n - 1, aux, dest, src, moves);
}

int main()
{
    FIO
    int n;
    cin >> n;
    vector<pair<int, int>> moves;
    hanoi(n, 1, 3, 2, moves);
    cout << moves.size() << "\n";
    for(auto p: moves) {
        cout << p.first << " " << p.second << '\n';
    }
    return 0;
}