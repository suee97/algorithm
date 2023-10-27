#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int maxVal = 210000000;

    int n;
    cin >> n;

    vector<vector<int>> v(n+1);

    int st, end, m;
    cin >> st >> end >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int dist[n+1];
    for (int i = 0; i < n+1; i++) dist[i] = maxVal;
    dist[st] = 0;

    queue<int> q;
    q.push(st);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            if (dist[v[cur][i]] != maxVal) continue;
            dist[v[cur][i]] = dist[cur] + 1;
            q.push(v[cur][i]);
        }
    }

    cout << (dist[end] == maxVal ? -1 : dist[end]);
}