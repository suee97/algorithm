#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    // n자리 이친수의 개수 구하기
    // 1. 1로 시작
    // 2. 1 연속 두개 이상x
    
    int n;
    cin >> n;

    long long dp[n+1];
    dp[1] = 1; // 1 -> 1
    dp[2] = 1; // 10 -> 1
    // 세자리 101, 100 -> 2
    // 네자리 1010, 1001, 1000 -> 3
    // 다섯자리 10101, 10100, 10010, 10001, 10000 -> 5

    // i+1 의 1의 개수 = i의 0의 개수
    // i+1 의 0의 개수 = i의 1의 개수 + i의 0의 개수
    // ...

    long long ans = -1;
    if (n <= 2) {
        cout << dp[n];
    } else {
        long long zeroCount = 1;
        long long oneCount = 0;
        for (int i = 3; i <= n; i++) {
            dp[i] = zeroCount * 2 + oneCount * 1;
            long long tmp = zeroCount;
            zeroCount = zeroCount + oneCount;
            oneCount = tmp;
        }

        cout << dp[n];
    }
}