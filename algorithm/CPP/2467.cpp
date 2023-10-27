#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int l = 0;
    int r = n-1;
    int val = INT_MAX;
    pair<int, int> ans;

    while (l < r) {
        if (abs(v[l] + v[r]) < val) {
            ans.first = v[l];
            ans.second = v[r];
            val = abs(v[l] + v[r]);
        }

        if (v[l] + v[r] == 0) {
            break;
        } else if (v[l] + v[r] < 0) {
            l++;
        } else if (v[l] + v[r] > 0) {
            r--;
        }
    }

    cout << ans.first << ' ' << ans.second;
    
}