#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<int> q;
    int dist[n+1];
    for (int i = 0; i < n+1; i++) {
        dist[i] = -1;
    }
    q.push(1);
    dist[1] = 0;

    vector<int> ans;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto i: v[cur]) {
            if (dist[i] != -1) continue;
            dist[i] = dist[cur] + 1;
            q.push(i);
        }
    }

    for (int i = 0; i < n+1; i++) {
        if (i == 1) continue;
        if (dist[i] != -1 && dist[i] <= 2) {
            ans.push_back(i);
        }
    }

    cout << ans.size();
}