#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int ans[t];
    for (int T = 0; T < t; T++) {
        int n;
        cin >> n;

        // 초기화
        int arr[n+1];
        int vis[n+1];
        int team[n+1];
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            vis[i] = 0;
            team[i] = -1;
        }

        // 로직
        for (int i = 1; i <= n; i++) {
            stack<pair<int, int>> s;

            if (vis[i] == 1) continue;
            s.push({i, arr[i]});
            vis[i] = 1;
            while (true) {
                pair<int, int> cur = s.top();
                if (vis[cur.second] == 1) {
                    break;
                }
                s.push({cur.second, arr[cur.second]});
                vis[cur.second] = 1;
            }

            // 출력
            // cout << "= stack =" << endl;
            // while (!s.empty()) {
            //     cout << "(" << s.top().first << ", " << s.top().second << ")" << endl;
            //     s.pop();
            // }

            if (s.size() == 1) {
                if (s.top().first == s.top().second) {
                    team[s.top().first] = 1;
                } else {
                    team[s.top().first] = 0;
                }
            }
            
            if (s.size() >= 2) {
                if (s.top().first == s.top().second) {
                    team[s.top().first] = 1;
                    s.pop();
                    while (!s.empty()) {
                        team[s.top().first] = 0;
                        s.pop();
                    }
                } else {
                    int isFound = 0;
                    stack<pair<int, int>> s_tmp;
                    int finding = s.top().second;
                    while (!s.empty()) {
                        s_tmp.push(s.top());
                        s.pop();
                        if (s_tmp.top().first == finding) {
                            isFound = 1;
                            break;
                        }
                    }
                    if (isFound) {
                        while (!s_tmp.empty()) {
                            team[s_tmp.top().first] = 1;
                            s_tmp.pop();
                        }
                        while (!s.empty()) {
                            team[s.top().first] = 0;
                            s.pop();
                        }
                    } else {
                        while (!s_tmp.empty()) {
                            team[s_tmp.top().first] = 0;
                            s_tmp.pop();
                        }
                    }
                }
            }
        }

        int count = 0;
        // cout << endl << "= team =" << endl;
        for (int i = 1; i <= n; i++) {
            // cout << team[i] << ' ';
            if (team[i] == 0) count++;
        }
        ans[T] = count;
    }
    for (int i = 0; i < t; i++) {
        cout << ans[i] << endl;
    }
}