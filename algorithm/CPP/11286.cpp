#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq_positive;
priority_queue<int> pq_negative;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) {
            pq_positive.push(tmp);
        } else if (tmp < 0) {
            pq_negative.push(tmp);
        } else { // tmp == 0
            if (pq_positive.empty() && !pq_negative.empty()) {
                cout << pq_negative.top() << '\n';
                pq_negative.pop();
            } else if (pq_negative.empty() && !pq_positive.empty()) {
                cout << pq_positive.top() << '\n';
                pq_positive.pop();
            } else if (pq_positive.empty() && pq_negative.empty()) {
                cout << "0" << '\n';
            } else {
                if (pq_positive.top() < abs(pq_negative.top())) {
                    cout << pq_positive.top() << '\n';
                    pq_positive.pop();
                } else {
                    cout << pq_negative.top() << '\n';
                    pq_negative.pop();
                }
            }
        }
    }
}