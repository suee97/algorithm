#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll lengthArr[81];

int main() {
    int n;
    cin >> n;

    lengthArr[1] = 1;
    lengthArr[2] = 1;
    for(int i = 3; i <= 80; i++) {
        lengthArr[i] = lengthArr[i-2] + lengthArr[i-1];
    }
    ll ans = lengthArr[n] * 4 + lengthArr[n-1] * 2;
    cout << ans;
}