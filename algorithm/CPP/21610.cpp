#include <iostream>
#include <vector>
using namespace std;

int board[51][51];
int n;
vector<pair<int, int>> grm;

int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int dagakX[4] = {-1, -1, 1, 1};
int dagakY[4] = {-1, 1, 1, -1};

void move(int d, int s) {
    vector<pair<int, int>> newGrm;

    for (int i = 0; i < grm.size(); i++) {
        int curX = grm[i].first;
        int curY = grm[i].second;

        for (int j = 0; j < s; j++) {
            curX += dx[d];
            curY += dy[d];

            if (curX < 1) curX = n;
            if (curX > n) curX = 1;

            if (curY < 1) curY = n;
            if (curY > n) curY = 1;
        }

        newGrm.push_back({curX, curY});
    }

    grm = newGrm;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    grm.push_back({n, 1});
    grm.push_back({n, 2});
    grm.push_back({n-1, 1});
    grm.push_back({n-1, 2});

    while (m--) {
        int d, s;
        cin >> d >> s;
        move(d, s);
        
        for (int i = 0; i < grm.size(); i++) {
            board[grm[i].first][grm[i].second]++;
        }
        
        for (int i = 0; i < grm.size(); i++) {
            int cnt = 0;
            
            for (int dir = 0; dir < 4; dir++) {
                int newX = grm[i].first + dagakX[dir];
                int newY = grm[i].second + dagakY[dir];
                if (newX < 1 || newY < 1 || newX > n || newY > n) continue;
                if (board[newX][newY]) cnt++;
            }
            board[grm[i].first][grm[i].second] += cnt;
        }

        vector<pair<int, int>> newGrm;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                bool isIn = 0;
                for (int k = 0; k < grm.size(); k++) {
                    if (grm[k].first == i && grm[k].second == j) isIn = 1;
                }
                
                if (!isIn && board[i][j] >= 2) {
                    board[i][j] -= 2;
                    newGrm.push_back({i, j});
                }
            }
        }

        grm = newGrm;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum += board[i][j];
        }
    }
    cout << sum;
}