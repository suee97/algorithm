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

    int dist[n+1];
    for (int i = 0; i < n+1; i++) dist[i] = -1;

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            if (dist[v[cur][i]] != -1) continue;
            q.push(v[cur][i]);
            dist[v[cur][i]] = dist[cur] + 1;
        }
    }

    int maxVal = -1;
    for (int i = 1; i < n+1; i++) {
        if (dist[i] > maxVal) maxVal = dist[i];
    }

    int cnt = 0;
    int where;
    for (int i = n; i >= 1; i--) {
        if (dist[i] == maxVal) {
            cnt++;
            where = i;
        }
    }

    cout << where << ' ' << maxVal << ' ' << cnt;
}