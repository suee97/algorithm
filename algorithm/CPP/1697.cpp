#include <bits/stdc++.h>
using namespace std;
int board[200002];
int vis[200002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int count = 0;
    board[N] = 0;
    vis[N] = 1;
    queue<int> Q;
    Q.push(N);

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if (cur*2 < 0 || cur*2 > 200002) continue;
        if (vis[cur+1] == 0) {
            if (cur+1 < 0) continue;;
            board[cur+1] = board[cur] + 1;
            vis[cur+1] = 1;
            Q.push(cur+1);
        }
        if (cur-1 < 0) continue;
        if (vis[cur-1] == 0) {
            board[cur-1] = board[cur] + 1;
            vis[cur-1] = 1;
            Q.push(cur-1);
        }
        if (vis[cur*2] == 0) {   
            board[cur*2] = board[cur] + 1;
            vis[cur*2] = 1;
            Q.push(cur*2);
        }
        if (cur+1 == K || cur-1 == K || cur*2 == K) {
            break;
        }
    }
    cout << board[K];
}