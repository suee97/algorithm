#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        int tmp = v.at(i).first;
        v.at(i).first = v.at(i).second;
        v.at(i).second = tmp;
    }

    int curEnd = -1;
    for (int i = 0; i < n; i++) {
        if (v.at(i).first >= curEnd) {
            curEnd = v.at(i).second;
            cnt++;
        }
    }
    cout << cnt;
}