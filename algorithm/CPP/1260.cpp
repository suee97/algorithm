#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int dfs_vis[2000];
vector<vector<int>> v(2000);

void dfs(int cur) {
    // while (!s.empty()) {
        dfs_vis[cur] = 1;
        cout << cur << ' ';
        for (int i = 0; i < v[cur].size(); i++) {
            if (dfs_vis[v[cur][i]] == 1) continue;
            
            // s.push(v[cur][i]);
            dfs(v[cur][i]);
        }
    // }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int startNode;
    cin >> startNode;

    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n+1; i++) {
        sort(v[i].begin(), v[i].end());
    }

    // dfs
    s.push(startNode);
    dfs_vis[startNode] = 1;

    dfs(startNode);

    cout << '\n';

    // bfs
    for (int i = 0; i < n+1; i++) {
        sort(v[i].begin(), v[i].end());
    }

    queue<int> q;
    int bfs_vis[n+1];
    q.push(startNode);
    for (int i = 0; i < n+1; i++) bfs_vis[i] = 0;
    bfs_vis[startNode] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int i = 0; i < v[cur].size(); i++) {
            if (bfs_vis[v[cur][i]] == 1) continue;
            bfs_vis[v[cur][i]] = 1;
            q.push(v[cur][i]);
        }
    }
}