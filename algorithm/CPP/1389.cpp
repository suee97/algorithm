#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> v(n+1);
    vector<int> resultVector(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n+1; i++) {
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }

    for (int i = 1; i < n+1; i++) {
        int dist[n+1];
        for (int j = 0; j < n+1; j++) dist[j] = -1;
        dist[i] = 0;

        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < v[cur].size(); j++) {
                if (dist[v[cur][j]] != -1) continue;
                q.push(v[cur][j]);
                dist[v[cur][j]] = dist[cur] + 1;
            }
        }
        int sum = 0;
        for (int j = 1; j < n+1; j++) sum += dist[j];
        resultVector[i] = sum;
    }

    int value = INT_MAX;
    int ans;
    for (int i = 1; i < n+1; i++) {
        if (resultVector[i] < value) {
            ans = i;
            value = resultVector[i];
        }
    }
    cout << ans;
}