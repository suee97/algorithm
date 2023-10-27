#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int board[n][n];

    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int maxNum = pow(2, n);
    for (int num = 0; num <= maxNum; num++) {
        int brute = num;
        vector<pair<int, int>> v1;
        vector<pair<int, int>> v2;
        for (int tmp = 0; tmp < n; tmp++) { 
            int val = brute % 2;
            brute /= 2;
            if (val == 0) {
                v1.push_back({tmp, val});
            } else {
                v2.push_back({tmp, val});
            }
        }

        if (v1.size() == v2.size()) {
            int v1_sum = 0;
            int v2_sum = 0;
            for (int i = 0; i < v1.size(); i++) {
                for (int j = 0; j < v1.size(); j++) {
                    v1_sum += board[v1[i].first][v1[j].first];
                    v2_sum += board[v2[i].first][v2[j].first];
                }
            }
            ans = min(ans, abs(v1_sum - v2_sum));
        }
    }
    cout << ans;
}