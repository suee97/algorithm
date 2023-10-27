#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int INF = 2140000000;

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> table[n+1];
    vector<vector<int>> path(n+1);
    int d[n+1];
    fill(d, d + n + 1, INF);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        table[a].push_back({b, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int start, end;
    cin >> start >> end;
    d[start] = 0;
    path[start].push_back(start);
    
    pq.push({0, start});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (cur.first != d[cur.second]) continue;
        
        for (auto e: table[cur.second]) {
            if (d[e.first] > d[cur.second] + e.second) {
                d[e.first] = d[cur.second] + e.second;
                pq.push({d[e.first], e.first});

                vector<int> tmp;
                for (auto p: path[cur.second]) {
                    tmp.push_back(p);
                }
                tmp.push_back(e.first);
                
                path[e.first] = tmp;
            }
        }
    }
    cout << d[end] << '\n' << path[end].size() << '\n';
    for (auto e: path[end]) {
        cout << e << ' ';
    }
}