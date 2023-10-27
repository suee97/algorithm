#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << '\n' << 1;
        return 0;
    }
    
    int dp[n+1];

    vector<int> ans;
    vector<int> track;
    int trackArr[n+1];

    dp[0] = -1;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++) {
        int num = INT_MAX;
        int action = -1;

        if (i % 3 == 0) {
            if (dp[i/3] + 1 < num) {
                num = dp[i/3] + 1;
                action = 3;
            }
        }
        if (i % 2 == 0) {
            if (dp[i/2] + 1 < num) {
                num = dp[i/2] + 1;
                action = 2;
            }
        }
        if (dp[i-1] + 1 < num) {
            num = dp[i-1] + 1;
            action = 0;
        }
        dp[i] = num;

        if (action == 3) {
            track.push_back(i / 3);
            trackArr[i] = i / 3;
        } else if (action == 2) {
            track.push_back(i / 2);
            trackArr[i] = i / 2;
        } else {
            track.push_back(i - 1);
            trackArr[i] = i - 1;
        }
    }

    trackArr[3] = 1;
    trackArr[2] = 1;

    cout << dp[n] << '\n';
    int findNum = n;
    while (1) {
        cout << findNum << ' ';
        findNum = trackArr[findNum];
        if (findNum == 1) {
            cout << findNum;
            break;
        }
    }
}