#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> empty_v;
    int maxValue = pow(n, m);

    for (int tmp = 0; tmp < maxValue; tmp++) {
        vector<int> v = empty_v;
        int brute = tmp;
        for (int i = 0; i < m; i++) {
            int dir = brute % n;
            brute /= n;
            v.push_back(dir+1);
        }
        vector<int> tmpV = v;
        sort(tmpV.begin(), tmpV.end());
        tmpV.erase(unique(tmpV.begin(), tmpV.end()), tmpV.end());
        if (tmpV.size() == m) {
            for (int i = v.size()-1; i >= 0; i--) {
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
    }
}