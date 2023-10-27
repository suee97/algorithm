#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n+1];
    for (int i = 0; i < n+1; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, ball;
        cin >> a >> b >> ball;
        for (int j = a; j <= b; j++) {
            arr[j] = ball;
        }
    }
    for (int i = 1; i < n+1; i++) {
        cout << arr[i] << ' ';
    }
}