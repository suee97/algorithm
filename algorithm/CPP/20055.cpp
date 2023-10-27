#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<int, bool>> v(n * 2);

    for (int i = 0; i < n * 2; i++) {
        int tmp;
        cin >> tmp;
        v[i] = {tmp, false};
    }

    int step = 0;

    while (1) {
        step++;

        // 1
        vector<pair<int, bool>> tmp_v(n * 2);
        for (int i = 0; i < n * 2; i++) {
            if (i == n * 2 - 1) {
                tmp_v[0] = v[i];
                continue;
            }
            tmp_v[i+1] = v[i];
        }
        v = tmp_v;
        v[n-1].second = false;
        

        // 2
        for (int i = n-2; i >= 0; i--) {
            if (v[i].second == true && v[i+1].first > 0 && v[i+1].second == false) {
                v[i].second = false;
                v[i+1].second = true;
                v[i+1].first--;
            }
        }
        v[n-1].second = false;

        // 3
        if (v[0].first > 0) {
            v[0].second = true;
            v[0].first--;
        }

        int cnt = 0;
        for (int i = 0; i < n * 2; i++) {
            if (v[i].first <= 0) {
                cnt++;
            }
        }
        if (cnt >= k) break;
    }

    cout << step;
    
}