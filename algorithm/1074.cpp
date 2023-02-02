#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int arr[2][2] = {
    {0, 1},
    {2, 3}
};

int func(int n, int r, int c) {
    if (n == 1) return arr[r][c];
    if (r < pow(2, n-1) && c < pow(2, n-1)) {
        return func(n-1, r, c);
    } else if (r < pow(2, n-1) && c >= pow(2, n-1)) {
        int val = pow(4, n-1) + func(n-1, r, c-pow(2, n-1));
        return val;
    } else if (r >= pow(2, n-1) && c < pow(2, n-1)) {
        int val = 2*pow(4, n-1) + func(n-1, r-pow(2, n-1), c);
        return val;
    } else {
        int val = 3*pow(4, n-1) + func(n-1, r-pow(2, n-1), c-pow(2, n-1));
        return val;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;
    cout << func(n, r, c);
}