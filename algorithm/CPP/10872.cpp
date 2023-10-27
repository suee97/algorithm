#include <bits/stdc++.h>
using namespace std;

int N;

int func(int n) {
    if (n == 1 || n == 0) return 1;
    int val = func(n-1) * n;
    return val;
}

int main() {
    cin >> N;
    cout << func(N);
}
