#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    int ans = 0;
    cin >> m >> n;

    vector<string> v;

    for (int i = 0; i < m; i++) {
        vector<pair<int, int>> tmp_v;
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            tmp_v.push_back({tmp, j});
        }
        stable_sort(tmp_v.begin(), tmp_v.end(), compare);

        int u_num = 2000001;

        string s = "";
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (j > 0 && tmp_v[j].first == tmp_v[j-1].first) {
                if (tmp_v[j-1].second > 2000000) {
                    tmp_v[j].second = tmp_v[j-1].second;
                } else {
                    u_num++;
                    tmp_v[j].second = u_num;
                    tmp_v[j-1].second = u_num;
                }
            }
            s += to_string(tmp_v[j].second);
        }
        v.push_back(s);
    }

    for (int i = 0; i < m; i++) {
        // cout << v[i] << ' ';
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            if (v[i] == v[j]) {
                ans++;
            }
        }
    }

    ans /= 2;
    cout << ans;
}
