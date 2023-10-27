#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    long long sum = v[0];
    int st = 0;
    int end = 0;
    int answer = 110000;

    while (1) {
        if (end >= n) break;

        if (sum >= s) {
            answer = min(answer, end - st + 1);
            st++;
            sum -= v[st-1];
            continue;
        }

        if (sum < s) {
            end++;
            sum += v[end];
            continue;
        }
    }

    if (answer == 110000) {
        cout << 0;
    } else {
        cout << answer;
    }
}
