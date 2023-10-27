#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

struct node_pair {
    int st;
    int end;
    double dist;
};

bool compare(node_pair a, node_pair b) {
    return a.dist < b.dist;
}

int main() {
    int n;
    double e;
    cin >> n;

    pair<int, int> nodes[n+1]; // x, y

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        nodes[i+1].first = tmp;
    }

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        nodes[i+1].second = tmp;
    }

    cin >> e;

    vector<node_pair> v; // {i, j}, x 는 i노드~j노드의 거리가 x라는 뜻
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) continue;
            double dist = (pow(nodes[i].first - nodes[j].first, 2) 
                                + pow(nodes[i].second - nodes[j].second, 2)) * e;
            node_pair tmp;
            tmp.st = i; tmp.end = j;
            tmp.dist = dist;
            v.push_back(tmp);
        }
    }

    // 오름차순 정렬
    sort(v.begin(), v.end(), compare);

    double total = 0;
    int parent[n+1];
    for (int i = 0; i < n+1; i++) parent[i] = i;

    for (int i = 0; i < v.size(); i++) {
        // 사이클 확인
        // if (parent[v[i].st] == parent[v[i].end]) continue;
        
        int a = v[i].st;
        while (1) {
            if (a == parent[a]) break;
            a = parent[a];
        }
        int b = v[i].end;
        while (1) {
            if (b == parent[b]) break;
            b = parent[b];
        }

        if (a == b) continue;
        if (a < b) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
        
        total += v[i].dist;
    }
    cout.precision(100);
    cout << round(total);
}