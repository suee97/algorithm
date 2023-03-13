#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int part_0 = 0;
    int part_1 = 0;

    cin >> s;

    if (s[0] == '0') {
        part_0++;
    } else {
        part_1++;
    }

    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i-1]) {
            if (s[i] == '0') {
                part_0++;
            } else {
                part_1++;
            }
        }
    }
    
    cout << min(part_0, part_1);
}