#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
vector<int> v;

int main() {
    cin >> n;
    if (n == 1) {
        int tmp;
        cin >> tmp;
        cout << tmp;
    } else if (n == 2) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        cout << tmp1 << '\n' << min(tmp1, tmp2);
    } else { // n > 2
        int f1, f2;
        cin >> f1 >> f2;
        pq1.push(min(f1, f2));
        pq2.push(max(f1, f2));
        v.push_back(f1); v.push_back(min(f1, f2));
        
        for (int i = 0; i < n-2; i++) {
            int tmp;
            cin >> tmp;
            if (i % 2 == 0) { // 짝수
                if (tmp <= pq2.top()) {
                    pq1.push(tmp);
                } else {
                    pq1.push(pq2.top());
                    pq2.pop();
                    pq2.push(tmp);
                }
            } else { // 홀수
                if (tmp >= pq1.top()) {
                    pq2.push(tmp);
                } else {
                    pq2.push(pq1.top());
                    pq1.pop();
                    pq1.push(tmp);
                }
            }
            v.push_back(pq1.top());
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v.at(i) << '\n';
    }
}