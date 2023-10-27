#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    int* vis = new int[10];
    fill(vis, vis + 10, 0);

    long long number = n;
    while (1) {
        int sum = 0;
        string s = to_string(number);
        
        for (int i = 0; i < s.length(); i++) vis[s[i] - '0'] = 1;
        
        for (int i = 0; i < 10; i++) sum += vis[i];
        if (sum == 10) {
            break;
        } else {
            number += n;
        }
    }

    cout << number;
}