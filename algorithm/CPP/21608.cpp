#include <bits/stdc++.h>
using namespace std;

int n;
int board[20][20];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool comp1(vector<int> a, vector<int> b) {
    return (a[2] > b[2]);
}

bool comp2(vector<int> a, vector<int> b) {
    return (a[3] > b[3]);
}

bool comp3(vector<int> a, vector<int> b) {
    return (a[0] < b[0]);
}

bool comp4(vector<int> a, vector<int> b) {
    return (a[1] < b[1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int st[n*n][5];
    int sum = 0;

    for (int i = 0; i < n*n; i++) {
        int st_num;
        cin >> st_num;
        st[i][0] = st_num;
        int like[4];
        for (int j = 0; j < 4; j++) {
            cin >> like[j];
            st[i][j+1] = like[j];
        }

        vector<vector<int>> v;

        for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < n; jj++) {
                if (board[ii][jj] != 0) {
                    continue;
                }                
                int tmp[4];
                tmp[0] = ii; tmp[1] = jj; tmp[2] = 0; tmp[3] = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = ii + dx[dir];
                    int ny = jj + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    for (int ll = 0; ll < 4; ll++) {
                        if (board[nx][ny] == like[ll]) {
                            tmp[2]++;
                        }
                    }
                    if (board[nx][ny] == 0) {
                        tmp[3]++;
                    }
                }
                v.push_back({tmp[0], tmp[1], tmp[2], tmp[3]});
            }
        }
        std::sort(v.begin(), v.end(), comp1);
        if (v.size() > 1 && v[0][2] == v[1][2]) {
            vector<vector<int>> v_tmp;
            for (int k = 0; k < v.size(); k++) {
                if (v[k][2] == v[0][2]) {
                    v_tmp.push_back({v[k][0], v[k][1], v[k][2], v[k][3]});
                }
            }
            v = v_tmp;
            std::sort(v.begin(), v.end(), comp2);
            if (v.size() > 1 && v[0][3] == v[1][3]) {
                vector<vector<int>> v_tmp;
                for (int k = 0; k < v.size(); k++) {
                    if (v[k][3] == v[0][3]) {
                        v_tmp.push_back({v[k][0], v[k][1], v[k][2], v[k][3]});
                    }
                }
                v = v_tmp;
                std::sort(v.begin(), v.end(), comp3);
                if (v.size() > 1 && v[0][0] == v[1][0]) {
                    vector<vector<int>> v_tmp;
                    for (int k = 0; k < v.size(); k++) {
                        if (v[k][0] == v[0][0]) {
                            v_tmp.push_back({v[k][0], v[k][1], v[k][2], v[k][3]});
                        }
                    }
                    v = v_tmp;
                    std::sort(v.begin(), v.end(), comp4);
                    board[v[0][0]][v[0][1]] = st_num;
                } else {
                    board[v[0][0]][v[0][1]] = st_num;
                }
            } else {
                board[v[0][0]][v[0][1]] = st_num;
            }
        } else {
            board[v[0][0]][v[0][1]] = st_num;
        }
    }

    for (int i = 0; i < n*n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (st[i][0] == board[j][k]) {
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = j + dx[dir];
                        int ny = k + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        for (int c = 1; c <= 4; c++) {
                            if (st[i][c] == board[nx][ny]) {
                                cnt++;
                            }
                        }
                    }
                }
            }
        }

        if (cnt == 1) {
            sum += 1;
        } else if (cnt == 2) {
            sum += 10;
        } else if (cnt == 3) {
            sum += 100;
        } else if (cnt == 4) {
            sum += 1000;
        }
    }

    cout << sum;
}