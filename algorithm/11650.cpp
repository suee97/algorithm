#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> arr[100000];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        arr[i] = {tmp1, tmp2};
    }

    stable_sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
}