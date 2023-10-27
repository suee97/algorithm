#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    long long p[101];
    p[1] = 1; p[2] = 1; p[3] = 1; p[4] = 2; p[5] = 2;
    for (int i = 6; i < 101; i++) {
        p[i] = p[i-1] + p[i-5];
    }

    vector<long long> ans;    

    while (t--) {
        int n;
        cin >> n;
        ans.push_back(p[n]);
    }
    
    for (auto i : ans) {
        cout << i << '\n';
    }
}