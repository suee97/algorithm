#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());

    // m = 5
    // 1 4 5 5 7 12

    int L_index = 0;
    int R_index = 0;
    int answer = INT_MAX;

    while (1) {
        if (R_index >= v.size()) break;

        if (v[R_index] - v[L_index] == m) {
            answer = m;
            break;
        }
        if (v[R_index] - v[L_index] < m) {
            R_index++;
        } else {
            if (v[R_index] - v[L_index] < answer) {
                answer = v[R_index] - v[L_index];
            }
            L_index++;
        }
    }

    cout << answer;

}