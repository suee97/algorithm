#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;

    priority_queue<int> pq;

    while (n--) {
        int command;
        cin >> command;

        if (command == 1) {
            int val;
            cin >> val;
            pq.push(val);
        }

        if (command == 2) {
            if (!pq.empty()) {
                cout << pq.top();
                pq.pop();
            } else {
                cout << -1;
            }
        }
    }
}