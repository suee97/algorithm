#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000];
int sum[1000];
int ans = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    sum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i-1] + arr[i];
    }
    for (int i = 0; i < n; i++) {
        ans += sum[i];
    }
    cout << ans;
}