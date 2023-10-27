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
        
        int vis[N+1];
        int dist[N+1];
        for (int i = 0; i < N+1; i++) {
            vis[i] = 0;
            dist[i] = INT_MAX;
        }
        
        // 1에서 출발한다고 가정 (다익스트라)
        // vis[1] = 1;
        dist[1] = 0;
        
        vector<vector<pair<int, int>>> v(500);
        for (int i = 0; i < M; i++) {
            int X, Y, C;
            cin >> X >> Y >> C;
            v[X].push_back({Y, C});
        }

        // for (int i = 0; i < v[1].size(); i++) {
        //     dist[v[1][i].first] = v[1][i].second;
        // }

        // int cur = 1;

        while (1) {
            int minVal = INT_MAX;
            int cur;
            for (int i = 1; i < N+1; i++) {
                if (dist[i] < minVal && vis[i] != 1) {
                    minVal = dist[i];
                    cur = i;
                }
            }

            if (minVal == INT_MAX) break;

            for (int i = 0; i < v[cur].size(); i++) {
                dist[v[cur][i].first] = min(dist[v[cur][i].first], dist[cur] + v[cur][i].second);
            }

            vis[cur] = 1;

            for (int i = 1; i < N+1; i++) {
                cout << dist[i] << ' ';
            }
            cout << '\n';
        }
    }
}