#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    unordered_map<int, string> map;
    unordered_map<string, int> map2;
    unordered_set<int> s;
    s.size()
    string ans = "";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        map[i+1] = s;
        map2[s] = i+1;
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9') {
            ans += map[stoi(s)] + '\n';
        } else {
            ans += to_string(map2[s]) + '\n';
        }
    }
    cout << ans;
}