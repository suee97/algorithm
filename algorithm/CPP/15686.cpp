#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[52][52];
vector<pair<int, int>> chickenHouse;
int maxTmp = 1;
int jisu = 0;
int minDistance = INT_MAX;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                chickenHouse.push_back({i, j});
                maxTmp *= 2; jisu++;
            }
        }
    }
    for (int tmp = 0; tmp < maxTmp; tmp++) {
        int brute = tmp;
        int oneCount = 0;
        int arr[chickenHouse.size()];
        for (int i = 0; i < jisu; i++) {
            int onOff = brute % 2;
            if (onOff == 1) {
                arr[i] = 1;
                oneCount++;
            } else {
                arr[i] = 0;
            }
            brute /= 2;
        }
        if (oneCount != m) continue;

        int sumDistance = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 1) continue;
                int minDist = 10000;
                for (int k = 0; k < jisu; k++) {
                    if (arr[k] != 1) continue;
                    int tmpDist = abs(i - chickenHouse.at(k).first) + abs(j - chickenHouse.at(k).second);
                    if (tmpDist < minDist) {
                        minDist = tmpDist;
                    }
                }
                sumDistance += minDist;
            }
        }
        if (sumDistance < minDistance) {
            minDistance = sumDistance;
        }
    }
    cout << minDistance;
}