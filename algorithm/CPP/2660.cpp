#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> v(n+1);
    vector<int> resultVector(n+1);
    
    while (1) {
        int a, b;
        cin >> a >> b;

        if (a == -1 || b == -1) break;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i < n+1; i++) {
        int dist[n+1];
        for (int j = 0; j < n+1; j++) dist[j] = -1;
        dist[i] = 0;

        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < v[cur].size(); j++) {
                if (dist[v[cur][j]] != -1) continue;
                dist[v[cur][j]] = dist[cur] + 1;
                q.push(v[cur][j]);
            }
        }

        int maxVal = -1;
        for (int j = 1; j < n+1; j++) {
            maxVal = max(maxVal, dist[j]);
        }
        resultVector[i] = maxVal;
    }

    int minVal = INT_MAX;
    for (int i = 1; i < n+1; i++) {
        minVal = min(minVal, resultVector[i]);
    }

    int candidateCount = 0;
    vector<int> candidates;
    for (int i = 1; i < n+1; i++) {
        if (resultVector[i] == minVal) {
            candidateCount++;
            candidates.push_back(i);
        }
    }
    sort(candidates.begin(), candidates.end());
    cout << minVal << ' ' << candidateCount << '\n';
    for (int i = 0; i < candidates.size(); i++) {
        cout << candidates[i] << ' ';
    }
}