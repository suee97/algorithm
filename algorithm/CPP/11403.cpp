#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int metrix[n][n];
    int ans[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> metrix[i][j];
            ans[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // i to j
            int vis[n];
            for (int k = 0; k < n; k++) vis[k] = 0;
            
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int k = 0; k < n; k++) {
                    if (metrix[cur][k] == 0 || vis[k] == 1) continue;
                    q.push(k);
                    vis[k] = 1;
                }
            }
            if (vis[j] == 1) ans[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}