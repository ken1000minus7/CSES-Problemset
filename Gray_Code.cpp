#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

string stringy(vector<char> &temp) {
    string ans = "";
    for(char c : temp) ans += c;
    return ans;
}



int main()
{
    FIO
    int n;
    cin >> n;
    for(int i = 0; i < pow(2, n); i++) {
        cout << bitset<32>(i ^ (i >> 1)).to_string().substr(32 - n) << "\n";
    }
    return 0;
}