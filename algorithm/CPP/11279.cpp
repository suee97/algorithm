#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(tmp);
        }
    }
}