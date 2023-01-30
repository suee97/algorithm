#include <bits/stdc++.h>
using namespace std;

int n, m;
queue<int> A, B;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int arr[n+m];
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        A.push(tmp);
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        B.push(tmp);
    }
    for (int i = 0; i < n+m; i++) {
        if (A.empty()) {
            cout << B.front() << ' ';
            B.pop();
        } else if (B.empty()) {
            cout << A.front() << ' ';
            A.pop();
        } else if (A.front() <= B.front()) {
            cout << A.front() << ' ';
            A.pop();
        } else {
            cout << B.front() << ' ';
            B.pop();
        }
    }
}