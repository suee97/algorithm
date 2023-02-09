#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int n;
int cnt = 0;

// 1일자 기준 index return
int getIndex(int month, int day) {
    switch (month)
    {
    case 1: return day-1;
        break;
    case 2: return 30+day;
        break;
    case 3: return 58+day;
        break;
    case 4: return 89+day;
        break;
    case 5: return 119+day;
        break;
    case 6: return 150+day;
        break;
    case 7: return 180+day;
        break;
    case 8: return 211+day;
        break;
    case 9: return 242+day;
        break;
    case 10: return 272+day;
        break;
    case 11: return 303+day;
        break;
    // 12
    default: return 333+day;
        break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({getIndex(a, b), getIndex(c, d)-1});
    }
    sort(v.begin(), v.end());


    
    cout << cnt;
}