#include <bits/stdc++.h>
using namespace std;

vector<int> find_match(int before, char cur) {
    vector<int> tmp;
    for (int i = 0; i < 16; i++) {
        int res1 = before & i;

        if (res1 == 0) continue;
        bool res2 = false;

        if (cur == 'A') {
            if (i & (1 << 3)) res2 = true;
        } else if (cur == 'B') {
            if (i & (1 << 2)) res2 = true;
        } else if (cur == 'C') {
            if (i & (1 << 1)) res2 = true;
        } else {
            if (i & 1) res2 = true;
        }

        if (res2 == false) continue;

        // cout << "i : " << i << " // ";
        // for (int j = 3; j >= 0; j--) {
        //     if (i & (1 << j)) {
        //         cout << 1 << ' ';
        //     } else {
        //         cout << 0 << ' ';
        //     }
        // }
        // cout << '\n';

        tmp.push_back(i);
    }
    return tmp;
}

int main() {
    string s;
    cin >> s;

    unordered_map<string, vector<int>> m;

    long long arr[16];
    fill(arr, arr+16, 0);

    arr[8] = 1;

    for (int i = 0; i < s.length(); i++) {
        long long tmpArr[16];
        fill(tmpArr, tmpArr+16, 0);

        char c = s[i];

        for (int j = 0; j < 16; j++) {
            long long times = arr[j] % 1000000007;

            if (!m[to_string(j) + s[i]].empty()) {
                for (auto e: m[to_string(j) + s[i]]) tmpArr[e] += times % 1000000007;
            } else {
                // cout << "char, j : " << s[i] << ' ' << j << '\n';
                vector<int> tmp = find_match(j, s[i]);
                m[to_string(j) + s[i]] = tmp;
                for (auto e: tmp) tmpArr[e] += times % 1000000007;
            }
        }

        for (int j = 0; j < 16; j++) {
            arr[j] = tmpArr[j];
        }
    }
    long long sum = 0;
    for (auto e: arr) sum += e % 1000000007;
    cout << sum % 1000000007 << '\n';
}