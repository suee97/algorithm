#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            pq.push(tmp);
        }
        priority_queue<int> tmp_pq;
        for (int j = 0; j < n; j++) {
            tmp_pq.push(pq.top());
            pq.pop();
        }
        pq = tmp_pq;
    }

    for (int i = 0; i < n-1; i++) {
        pq.pop();
    }

    cout << pq.top();
}