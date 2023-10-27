#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a_n, b_n;
    cin >> a_n >> b_n;

    unordered_set<int> s;

    for (int i = 0; i < a_n; i++) {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    for (int i = 0; i < b_n; i++) {
        int tmp;
        cin >> tmp;
        if (s.find(tmp) != s.end()) {
            s.erase(tmp);
        }
    }

    vector<int> v;

    if (s.size() == 0) {
        cout << 0;
    } else {
        cout << s.size() << '\n';
        for (auto e: s) v.push_back(e);
        sort(v.begin(), v.end());
        for (auto e: v) cout << e << ' ';
    }

}