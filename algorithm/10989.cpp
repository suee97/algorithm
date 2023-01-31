#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp]++;
    }
    for (int i = 1; i < 10001; i++) {
        int count = arr[i];
        for (int j = 0; j < count; j++) {
            cout << i << '\n';
        }
    }
}