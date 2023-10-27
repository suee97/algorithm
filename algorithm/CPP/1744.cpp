#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    vector<long long> e; 

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    stack<int> s1;
    stack<int> s2;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= 0) {
            if (s1.empty()) {
                s1.push(v[i]);
            } else {
                e.push_back(s1.top() * v[i]);
                s1.pop();
            }
        }
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == 1) e.push_back(v[i]);
        if (v[i] > 1) {
            if (s2.empty()) {
                s2.push(v[i]);
            } else {
                e.push_back(s2.top() * v[i]);
                s2.pop();
            }
        }
    }

    if (!s1.empty()) {
        e.push_back(s1.top());
    }
    if (!s2.empty()) {
        e.push_back(s2.top());
    }

    long long ans = 0;
    for (int i = 0; i < e.size(); i++) {
        ans += e[i];
    }
    cout << ans;
}