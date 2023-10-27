// 못풂

#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int op = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    int arr[10];
    for (int i = 0; i < 10; i++) {
        op = ((op % 10) * (a % 10)) % 10;
        arr[i] = op;
        cout << op << ' ';
    }

}