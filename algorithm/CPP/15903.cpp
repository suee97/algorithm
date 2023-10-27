#include <bits/stdc++.h>
using namespace std;

int n, m;
long long sum = 0;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    while (m--) {
        long long a, b;
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        long long aa = a + b; long long bb = a + b;
        pq.push(aa); pq.push(bb);
    }

    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
}