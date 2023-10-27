#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int answer = 0;

    vector<int> left;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = j; k < n; k++) {
                int num = v[i] + v[j] + v[k];
                if (binary_search(v.begin() + k, v.end(), num)) {
                    answer = max(answer, num);
                }
            }
        }
    }

    cout << answer;

}