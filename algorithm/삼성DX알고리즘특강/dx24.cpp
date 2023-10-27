#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int board[n][n];
    int dist[n][n];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            board[i][j] = s[j] - '0';
        }
        for (int j = 0; j < n; j++) dist[i][j] = -1;
    }

    dist[0][0] = 0;
    for (int num = 1; num < n; num++) {
        int x = num;
        int y = 0;
        
        while (1) {
            if (y >= n) break;

            int left = 1000000000;
            int top = 1000000000;
            if (y - 1 >= 0) {
                left = dist[x][y-1];
            }
            if (x - 1 >= 0) {
                top = dist[x-1][y];
            }
            
            dist[x][y] = left > top ? top + board[x][y] : left + board[x][y];
            x -= 1; y += 1;
        }
    }

     for (int num = 1; num < n; num++) {
        int x = n-1;
        int y = num;
        
        while (1) {
            if (y >= n) break;

            int left = 1000000000;
            int top = 1000000000;
            if (y - 1 >= 0) {
                left = dist[x][y-1];
            }
            if (x - 1 >= 0) {
                top = dist[x-1][y];
            }
            
            dist[x][y] = left > top ? top + board[x][y] : left + board[x][y];
            x -= 1; y += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << dist[n-1][n-1];
    
}