#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    // 2 4 -10 4 6
    // 정렬: -10 2 4 4 6
    // 답: 0 1 2 2 3
    // 6은 어떻게 계산이 되는가

    // -10,2  2,0  4,1  4,3  6,4

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int sorted[n];
    int answer[n];

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back({tmp, i});
        sorted[i] = tmp;
    }

    sort(sorted, sorted + n);
    sort(v.begin(), v.end(), compare);

    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            answer[v[0].second] = 0;
            continue;
        }
        if (v[i-1].first != v[i].first) {
            cur++;
            answer[v[i].second] = cur;
        } else {
            answer[v[i].second] = cur;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }
}