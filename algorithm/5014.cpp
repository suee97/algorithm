#include <bits/stdc++.h>
using namespace std;

int vis[1000000];

int main() {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    int dist[f];
    for (int i = 0; i < f; i++) {
        dist[i] = -1;
    }

    vis[s-1] = 1;
    dist[s-1] = 0;

    int dx[2] = {u, -d};
    
    queue<int> Q;
    Q.push(s-1);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 2; dir++) {
            int nx = cur + dx[dir];
            if (nx < 0 || nx >= f) continue;
            if (vis[nx] == 1) continue;
            vis[nx] = 1;
            Q.push(nx);
            dist[nx] = dist[cur] + 1;
        }
    }
    if (dist[g-1] != -1) {
        cout << dist[g-1];
    } else {
        cout << "use the stairs";
    }
}