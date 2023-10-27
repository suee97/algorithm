#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int MAX_VAL = 2100000000;

    int v, e;
    cin >> v >> e;

    int board[v+1][v+1];
    int d[v+1]; // min distance
    for (int i = 0; i < v+1; i++) d[i] = MAX_VAL;
    for (int i = 0; i < v+1; i++) {
        for (int j = 0; j < v+1; j++) {
            board[i][j] = MAX_VAL;
        }
    }

    int start;
    cin >> start;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = min(board[a][b], c);
    }

    // 거리, 정점
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    d[start] = 0;

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        
        if (d[cur.second] != cur.first) continue;
        for (int i = 1; i < v+1; i++) {
            if (board[cur.second][i] == MAX_VAL) continue;
            if (d[i] > board[cur.second][i] + d[cur.second]) {
                d[i] = board[cur.second][i] + d[cur.second];
                pq.push({d[i], i});
            }
        }
    }

    for (int i = 1; i < v+1; i++) {
        if (d[i] == MAX_VAL) {
            cout << "INF\n";
        } else {
            cout << d[i] << '\n';
        }
    }

    return 0;
}