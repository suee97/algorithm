#include <bits/stdc++.h>
using namespace std;

tuple<int, int, string> arr[100000];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        string s;
        cin >> tmp >> s;
        arr[i] = {tmp, i, s};
    }

    stable_sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        cout << get<0>(arr[i]) << ' ' << get<2>(arr[i]) << '\n';
    }

}