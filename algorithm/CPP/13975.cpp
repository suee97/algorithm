#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sum = 0;
        int k;
        cin >> k;
        while (k--) {
            int tmp;
            cin >> tmp;
            pq.push(tmp);
        }
        while (pq.size() > 1) {
            ll t1 = pq.top();
            pq.pop();
            ll t2 = pq.top();
            pq.pop();
            pq.push(t1 + t2);
            sum += t1 + t2;
        }
        cout << sum << '\n';
    }
}