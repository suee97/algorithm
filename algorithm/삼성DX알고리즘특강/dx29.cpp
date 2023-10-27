#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int size1, size2;
    cin >> size1 >> size2;

    int cnt = 0;
    unordered_map<string, bool> um;

    for (int i = 0; i < size1; i++) {
        string s; cin >> s;
        um[s] = 1;
    }
    for (int i = 0; i < size2; i++) {
        string s; cin >> s;
        if (um[s] == 1) cnt++;
    }

    cout << cnt;

    
}