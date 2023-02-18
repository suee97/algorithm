#include <bits/stdc++.h>
using namespace std;

int n;
int sum = 0;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), compare);
    cout << ">> Sorted" << '\n';
    for (int i = 0; i < n; i++) {
        cout << v.at(i).first << ' ' << v.at(i).second << '\n';
    }
    
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (t < v.at(i).first) {
            sum += v.at(i).second;
            t++;
        }
    }
    cout << sum;
}