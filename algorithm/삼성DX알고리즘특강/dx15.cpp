#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> coreList;

    int board[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            coreList.push_back({i, j});
        }
    }

    

}