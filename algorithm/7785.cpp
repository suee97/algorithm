#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    unordered_map<string, string> m;
    while (n--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        if (s2 == "leave") {
            m.erase(s1);
        } else { 
            m[s1] = s2;
        }
    }

    for (auto e : m) {
        v.push_back(e.first);
    }
    sort(v.begin(), v.end());
    while(!v.empty()) {
        cout << v.back() << '\n';
        v.pop_back();
    }
}