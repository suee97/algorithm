#include <bits/stdc++.h>
using namespace std;

int n;
int Rcount;
queue<pair<int, int>> q;

int recursion(const char *s, int l, int r){
    Rcount++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        Rcount = 0;
        string s;
        cin >> s;
        q.push({isPalindrome(&s[0]), Rcount});
    }

    for (int i = 0; i < n; i++) {
        cout << q.front().first << ' ' << q.front().second << endl;
        q.pop();
    }
}