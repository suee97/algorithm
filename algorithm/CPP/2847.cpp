#include <bits/stdc++.h>
using namespace std;

int arr[101];
int n;
int cnt = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n-2; i >= 0; i--) {
        if (arr[i] < arr[i+1]) continue;
        while(1) {
            arr[i]--;
            cnt++;
            if (arr[i] < arr[i+1]) break;
        }
    }

    cout << cnt;
}