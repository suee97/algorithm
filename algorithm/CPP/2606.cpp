#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int k;
    cin >> n >> k;
    vector<vector<int>> v(101);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int cnt = 0;
    queue<int> q;
    int vis[101];
    for (int i = 0; i < 101; i++) vis[i] = 0;
    vis[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            if (vis[v[cur][i]] == 0) {
                q.push(v[cur][i]);
                vis[v[cur][i]] = 1;
            }
        }
    }

    for (int i = 0; i < 101; i++) {
        if (vis[i] == 1) cnt++;
    }

    cout << cnt - 1;
}