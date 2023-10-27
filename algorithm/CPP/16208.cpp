#include <bits/stdc++.h>
#define ll long long
using namespace std;
int arr[500001];

int main() {
    int n;
    ll remain = 0;
    ll sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        remain += arr[i];
    }
    
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        remain = remain - arr[i];
        sum += remain * arr[i];
    }
    cout << sum;
}