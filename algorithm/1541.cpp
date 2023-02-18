#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> splited;
vector<int> computed;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int prev = 0;
    int cur;
    cur = s.find('-');
    while (cur != string::npos) {
        string substring = s.substr(prev, cur - prev);
        splited.push_back(substring);
        prev = cur + 1;
        cur = s.find('-', prev);
    }
    splited.push_back(s.substr(prev, cur - prev));

    int max = -1;
    int maxIndex;
    for (int i = 0; i < splited.size(); i++) {
        // +로 split해서 computed에 넣기
        int p = 0;
        int c;
        int sum = 0;
        c = splited[i].find('+');
        while (c != string::npos) {
            string subst = splited[i].substr(p, c - p);
            sum += stoi(subst);
            p = c + 1;
            c = splited[i].find('+', p);
        }
        sum += stoi(splited[i].substr(p, c - p));
        computed.push_back(sum);

        // max값과 maxIndex 찾기
        if (sum > max) {
            max = sum;
            maxIndex = i;
        }
    }
    splited[maxIndex] = to_string(max);
    string ansS = "";
    for (int i = 0; i < splited.size(); i++) {
        if (i == 0) {
            ansS += splited[i];
        } else {
            ansS += "-" + splited[i];
        }
    }
    ansS = "+" + ansS;
    cout << ansS << '\n';
    
}