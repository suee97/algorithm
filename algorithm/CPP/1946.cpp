#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;

    while (t--) {
        int n;
        int cnt = 0;
        vector<pair<int, int>> v;
        priority_queue<int, vector<int>, greater<int>> pq;

        cin >> n;
        for (int i = 0; i < n; i++) {
            int tmpA, tmpB;
            cin >> tmpA >> tmpB;
            v.push_back({tmpA, tmpB});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if (pq.empty()) {
                pq.push(v[i].second);
                cnt++;
                continue;
            }
            if (v[i].second <= pq.top()) {
                cnt++;
                pq.push(v[i].second);
            }
        }
        cout << cnt << '\n';
    }
}