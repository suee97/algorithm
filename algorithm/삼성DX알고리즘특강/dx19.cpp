#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

struct Distance {
    int st;
    int end;
    int dist;
};

bool compare(Distance a, Distance b) {
    return a.dist < b.dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> um;
    vector<Distance> v;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        um[a] = a;
        um[b] = b;

        Distance tmp;
        tmp.st = a; tmp.end = b; tmp.dist = c;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), compare);

    long long total = 0;
    for (int i = 0; i < m; i++) {
        int a = v[i].st;
        while (1) {
            if (a == um[a]) break;
            a = um[a];
        }

        int b = v[i].end;
        while (1) {
            if (b == um[b]) break;
            b = um[b];
        }

        if (a == b) continue; // 사이클 존재

        if (a > b) {
            um[a] = b;
        } else {
            um[b] = a;
        }

        total += v[i].dist;
    }

    cout << total;

}