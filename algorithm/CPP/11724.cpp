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

    int vis[n+1];
    for (int i = 0; i < n+1; i++) {
        vis[i] = 0;
    }

    queue<int> q;
    int cnt = 0;

    for (int i = 1; i < n+1; i++) {
        if (vis[i] == 0) cnt++;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < v[cur].size(); j++) {
                if (vis[v[cur][j]] == 0) {
                    q.push(v[cur][j]);
                    vis[v[cur][j]] = 1;
                }
            }
        }
    }

    cout << cnt;

}