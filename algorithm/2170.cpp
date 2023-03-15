#include <bits/stdc++.h>
using namespace std;

int n;
int global_sum = 0;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int start = v[0].first;
    int end = v[0].second;
    for (int i = 1; i < n; i++) {
        if (end < v[i].first) {
            global_sum += end - start;
            start = v[i].first;
            end = v[i].second;
        } else {
            if (end < v[i].second) {
                end = v[i].second;
            }
            if (start > v[i].first) {
                start = v[i].first;
            }
        }
    }
    global_sum += end - start;
    cout << global_sum;
}