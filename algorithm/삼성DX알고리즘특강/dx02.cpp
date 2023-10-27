#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int com = pow(2, n) - 1;

    if ((com & m) == com) {
        cout << "ON" << '\n';
    } else {
        cout << "OFF" << '\n';
    }
}