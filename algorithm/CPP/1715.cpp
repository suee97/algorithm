#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;
int sum = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    while (!(pq.size() == 1)) {
        int op1 = pq.top();
        pq.pop();
        int op2 = pq.top();
        pq.pop();
        sum += op1 + op2;
        pq.push(op1 + op2);
    }
    cout << sum;
}