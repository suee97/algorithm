#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int tot = 0;

    vector<vector<int>> tree(n+1);
    int parent[n+1]; // i의 부모는 parent[i]
    parent[1] = 0;
    for (int i = 2; i <= n; i++) {
        int tmp;
        cin >> tmp;
        parent[i] = tmp;
        tree[tmp].push_back(i);
    }

    vector<vector<int>> parents_list(n+1);
    parents_list[0].push_back(0);

    bool vis[n+1];
    memset(vis, false, sizeof(vis));

    queue<int> q;
    q.push(1);
    vis[1] = 1;

    int before = 1;

    while (!q.empty()) {
        int cur = q.front();
        int after = cur;

        // befor와 after 거리 계산
        // cout << before << " ~ " << after << " 거리 계산 ";
        // cout << "[ " << cur << " 방문 ]\n";

        vector<int> before_mom, after_mom;

        parents_list[before].resize(parents_list[parent[before]].size());
        copy(parents_list[parent[before]].begin(), parents_list[parent[before]].end(), parents_list[before].begin());
        parents_list[before].push_back(before);
        // cout << "before: " << before << " 의 부모 리스트 \n";
        // for (int i = 0; i < parents_list[before].size(); i++) {
        //     cout << parents_list[before][i] << ' ';
        // }
        // cout << '\n';
        

        parents_list[after].resize(parents_list[parent[after]].size());
        copy(parents_list[parent[after]].begin(), parents_list[parent[after]].end(), parents_list[after].begin());
        parents_list[after].push_back(after);
        // cout << "before: " << after << " 의 부모 리스트 \n";
        // for (int i = 0; i < parents_list[after].size(); i++) {
        //     cout << parents_list[after][i] << ' ';
        // }
        // cout << '\n';

        // int tmp = before;
        // while (tmp) {
        //     before_mom.push_back(tmp);
        //     tmp = parent[tmp];
        // }

        // tmp = after;
        // while (tmp) {
        //     after_mom.push_back(tmp);
        //     tmp = parent[tmp];
        // }
        int before_dist = 0;
        int after_dist = 0;

        // cout << "before mom" << "  ";
        // for (int i = 0; i < before_mom.size(); i++) {
        //     cout << before_mom[i] << ' ';
        // }
        // cout << '\n';

        // cout << "after mom" << "  ";
        // for (int i = 0; i < after_mom.size(); i++) {
        //     cout << after_mom[i] << ' ';
        // }
        // cout << '\n';

        // int common;
        // bool isBreak = false;
        // for (int i = 0; i < before_mom.size(); i++) {
        //     if (isBreak) break;
        //     for (int j = 0; j < after_mom.size(); j++) {
        //         if (isBreak) break;
        //         if (before_mom[i] == after_mom[j]) {
        //             common = before_mom[i];
        //             before_dist = i;
        //             after_dist = j;
        //             isBreak = true;
        //         }
        //     }
        // }

        int common;
        bool isBreak = false;
        for (int i = parents_list[before].size() - 1; i >= 0; i--) {
            if (isBreak) break;
            for (int j = parents_list[after].size() - 1; j >= 0; j--) {
                if (isBreak) break;
                if (parents_list[before][i] == parents_list[after][j]) {
                    common = parents_list[before][i];
                    before_dist = parents_list[before].size() - i - 1;
                    after_dist = parents_list[after].size() - j - 1;
                    isBreak = true;
                }
            }
        }

        // cout << "common : " << common << '\n';
        // cout << "거리 : " << before_dist + after_dist << '\n';

        tot += before_dist + after_dist;
        q.pop();

        for (int i = 0; i < tree[cur].size(); i++) {
            if (!vis[tree[cur][i]]) {
                q.push(tree[cur][i]);
                vis[tree[cur][i]] = 1;
            }
        }

        before = cur;

    }
    cout << tot;
}