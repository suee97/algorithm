#include <iostream>
#include <queue>
#define INF 2100000000
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, x;
    cin >> n >> m >> x;
    
    vector<pair<int, int>> table1[n+1];
    vector<pair<int, int>> table2[n+1]; // 반대방향

    int d1[n+1];
    int d2[n+1]; // 반대방향
    
    fill(d1, d1+n+1, INF);
    fill(d2, d2+n+1, INF);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        table1[a].push_back({b, c});
        table2[b].push_back({a, c});
    }

    d1[x] = 0;
    d2[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.first != d1[cur.second]) continue;

        for (auto e: table1[cur.second]) {
            if (d1[e.first] > d1[cur.second] + e.second) {
                d1[e.first] = d1[cur.second] + e.second;
                pq.push({d1[e.first], e.first});
            }
        }
    }

    pq.push({0, x});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.first != d2[cur.second]) continue;

        for (auto e: table2[cur.second]) {
            if (d2[e.first] > d2[cur.second] + e.second) {
                d2[e.first] = d2[cur.second] + e.second;
                pq.push({d2[e.first], e.first});
            }
        }
    }
    int maxSum = 0;
    for (int i = 1; i <= n; i++) {
        maxSum = max(maxSum, d1[i]+d2[i]);
    }
    cout << maxSum;
}