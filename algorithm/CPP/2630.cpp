#include <bits/stdc++.h>
using namespace std;

int arr[130][130];

pair<int, int> recursion(int x, int y, int n) {
    if (n == 1) {
        if (arr[x][y] == 0) {
            return {1, 0};
        } else {
            return {0, 1};
        }
    }

    int blueCnt = 0;
    int whiteCnt = 0;
    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++) {
            if (arr[i][j] == 1) {
                blueCnt++;
            } else {
                whiteCnt++;
            }
        }
    }
    
    if (blueCnt == 0) {
        return {1, 0};
    }
    if (whiteCnt == 0) {
        return {0, 1};
    }

    pair<int, int> a = recursion(x, y, n/2);
    pair<int, int> b = recursion(x, y + n/2, n/2);
    pair<int, int> c = recursion(x + n/2, y, n/2);
    pair<int, int> d = recursion(x + n/2, y + n/2, n/2);

    return {a.first + b.first + c.first + d.first, a.second + b.second + c.second + d.second};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    pair<int, int> ans = recursion(0, 0, n);
    cout << ans.first << '\n' << ans.second;
}