#include <iostream>
#include <string.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    string base; string find;
    cin >> base >> find;
    
    int string_size = find.length();
    
    
    int idx = 0;
    int cnt = 0;
    while (idx != base.length() - string_size + 1) {
        string s = base.substr(idx++, string_size);

    }

    cout << cnt;

}