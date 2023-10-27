#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;
        
        vector<vector<pair<int, int>>> v(500);

        for (int i = 0; i < M; i++) {
            int X, Y, C;
            cin >> X >> Y >> C;
            v[X].push_back({Y, C});
        }

        vector<int> res;

        for (int st = 1; st <= N; st++) {
            int vis[N+1];
            int dist[N+1];
            for (int i = 0; i < N+1; i++) {
                vis[i] = 0;
                dist[i] = INT_MAX;
            }

            int minimum = INT_MAX;
            int cur;
            for (auto e: v[st]) {
                dist[e.first] = e.second;
                if (e.second < minimum) {
                    minimum = e.second;
                    cur = e.first;
                }
            }

            if (minimum == INT_MAX) continue;

            while (1) {
                for (int i = 0; i < v[cur].size(); i++) {
                    dist[v[cur][i].first] = min(dist[v[cur][i].first], dist[cur] + v[cur][i].second);
                }
                vis[cur] = 1;

                int minVal = INT_MAX;
                for (int i = 1; i <= N; i++) {
                    if (dist[i] < minVal && vis[i] != 1) {
                        minVal = dist[i];
                        cur = i;
                    }
                }
                if (minVal == INT_MAX) break;
            }

            // cout << "st: " << st << " 일때의 다익스트라 -> ";
            // for (int i = 1; i <= N; i++) {
            //     cout << dist[i] << ' ';
            // }
            // cout << '\n';

            res.push_back(dist[st]);
        }

        int ans = INT_MAX;
        for (auto e: res) ans = min(ans, e);

        if (ans != INT_MAX) {
            cout << '#' << T+1 << ' ' << ans;
        } else {
            cout << '#' << T+1 << -1;
        }
        cout << '\n';
    }
}