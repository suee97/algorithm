#include <bits/stdc++.h>
using namespace std;

int n;
int num;
int board[2200][2200];
int ans_1 = 0;
int ans0 = 0;
int ans1 = 0;

void func(pair<int, int> st, int n) {
    // 하나만 남았을 때
    if (n == 0) {
        if (board[st.first][st.second] == -1) {
            ans_1++;
        } else if (board[st.first][st.second] == 0) {
            ans0++;
        } else {
            ans1++;
        }
        return;
    }

    // 전부 같은 숫자일 때
    int cnt = 0;
    int tmp_1 = 0;
    int tmp0 = 0;
    int tmp1 = 0;
    for (int i = st.first; i < st.first + pow(3, n); i++) {
        for (int j = st.second; j < st.second + pow(3, n); j++) {
            cnt++;
            if (board[i][j] == -1) tmp_1++;
            if (board[i][j] == 0) tmp0++;
            if (board[i][j] == 1) tmp1++;
        }
    }
    if (cnt == tmp_1) {
        ans_1++;
        return;
    } else if (cnt == tmp0) {
        ans0++;
        return;
    } else if (cnt == tmp1) {
        ans1++;
        return;
    }

    for (int i = st.first; i < st.first + pow(3, n); i += pow(3, n-1)) {
        for (int j = st.second; j < st.second + pow(3, n); j += pow(3, n-1)) {
            func({i, j}, n-1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> board[i][j];
        }
    }
    if (num == 1) {
        n = 0;
    } else {
        n = log10(num) / log10(3);
    }
    func({0, 0}, n);
    cout << ans_1 << '\n' << ans0 << '\n' << ans1;
}