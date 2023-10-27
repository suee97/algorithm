#include <bits/stdc++.h>
using namespace std;

int func(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int val = func(n-1) + func(n-2);
    return val;
}

int main() {
    int N;
    cin >> N;
    cout << func(N);
}