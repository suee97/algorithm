#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

vector<ll> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int test = 0; test < t; test++) {
        int n;
        ll sum = 0;
        vector<int> v;
        vector<pair<int, int>> sorted;

        cin >> n;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
            sorted.push_back({tmp, i});
        }

        sort(sorted.begin(), sorted.end(), compare);

        int curMaxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (i < sorted[curMaxIndex].second) {
                sum += sorted[curMaxIndex].first - v[i];
            } else if (i == sorted[curMaxIndex].second) {
                if (i == n-1) continue;
                while (1) {
                    curMaxIndex++;
                    if (i < sorted[curMaxIndex].second) {
                        break;
                    }
                }
            }
        }
        
        ans.push_back(sum);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}