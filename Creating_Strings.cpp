#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;

void dostuff(int i, vector<char> &s, set<string> &ans) {
    if(i >= s.size()) {
        string perm = "";
        for(char c : s) {
            perm += c;
        }
        ans.insert(perm);
        return;
    }
    dostuff(i + 1, s, ans);
    for(int j = i + 1; j < s.size(); j++) {
        if(s[i] == s[j]) continue;
        swap(s[i], s[j]);
        dostuff(i + 1, s, ans);
        swap(s[i], s[j]);
    }
}

int main()
{
    FIO
    string ss;
    cin >> ss;
    vector<char> s;
    for(int i = 0; i < ss.length(); i++) {
        s.push_back(ss[i]);
    }
    set<string> ans;
    dostuff(0, s, ans);
    cout << ans.size() << "\n";
    for(string a : ans) {
        cout << a << '\n';
    }
    return 0;
}