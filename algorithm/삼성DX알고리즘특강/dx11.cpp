#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node* parent;
};

int main() {
    node pool[10001];
    for (int i = 0; i < 10001; i++) pool[i].val = i;
    int V, E, nodeA, nodeB;
    cin >> V >> E >> nodeA >> nodeB;
    for (int i = 0; i < E; i++) {
        int p, c;
        cin >> p >> c;
        pool[c].parent = &pool[p];

        if (pool[p].left == nullptr) {
            pool[p].left = &pool[c];
        } else {
            pool[p].right = &pool[c];
        }
    }

    node* root = &pool[1];
    pool[1].parent = nullptr;

    vector<int> trackA;
    vector<int> trackB;

    node* cur = &pool[nodeA];
    cout << "trackA : ";
    while (cur) {
        cout << cur->val << ' ';
        trackA.push_back(cur->val);
        cur = cur->parent;
    }
    cout << '\n';

    cur = &pool[nodeB];
    cout << "trackB : ";
    while (cur) {
        cout << cur->val << ' ';
        trackB.push_back(cur->val);
        cur = cur->parent;
    }
    cout << '\n';

    vector<int> ans;
    for (int i = 0; i < trackA.size(); i++) {
        for (int j = 0; j < trackB.size(); j++) {
            if (trackA[i] == trackB[j]) {
                ans.push_back(trackA[i]);
                break;
            }
        }
    }
    
    int res = ans[0];
    stack<int> s;
    s.push(res);
    int cnt = 1;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (pool[cur].left) {
            s.push(pool[cur].left->val);
            cnt++;
        }
        if (pool[cur].right) {
            s.push(pool[cur].right->val);
            cnt++;
        }
    }

    cout << res << ' ' << cnt;

}