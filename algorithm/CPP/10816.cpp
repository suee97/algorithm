#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[500000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    cin >> m;
    while (m--) {
        int tmp;
        cin >> tmp;
        int u = upper_bound(arr, arr+n, tmp) - arr;
        int l = lower_bound(arr, arr+n, tmp) - arr;
        cout << u - l << ' ';
    }
}