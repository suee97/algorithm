#include <iostream>
#include <sstream>
using namespace std;

struct node {
    string key;
    node* left;
    node* right;
};

int cal(node* root) {
    int leftOp;
    int rightOp;
    int res;
    
    // 마지막 노드인 경우
    if (!root->left && !root->right) {
        return stoi(root->key);
    }

    if (root->left) {
        leftOp = cal(root->left);
    }
    if (root->right) {
        rightOp = cal(root->right);
    }
    
    if (root->key[0] == '+') {
        res = leftOp + rightOp;
    } else if (root->key[0] == '/') {
        res = leftOp / rightOp;
    } else if (root->key[0] == '-') {
        res = leftOp - rightOp;
    } else if (root->key[0] == '*') {
        res = leftOp * rightOp;
    }

    return res;
}

int main() {
    string n;
    getline(cin, n);

    node pool[1001];

    string tmp;

    for (int i = 0; i < stoi(n); i++) {
        int idx; string value; int left; int right;

        getline(cin, tmp);
        stringstream ss;
        string splited;
        ss.str(tmp);
        int cnt = 0;
        while (ss >> splited) {
            if (cnt == 0) {
                idx = stoi(splited);
            } else if (cnt == 1) {
                value = splited;
            } else if (cnt == 2) {
                left = stoi(splited);
            } else if (cnt == 3) {
                right = stoi(splited);
            }
            cnt++;
        }

        pool[idx].key = value;
        if (cnt == 2) {
            pool[idx].left = nullptr;
            pool[idx].right = nullptr;
        }
        if (cnt == 3) {
            pool[idx].left = &pool[left];
            pool[idx].right = nullptr;
        }
        if (cnt == 4) {
            pool[idx].left = &pool[left];
            pool[idx].right = &pool[right];
        }

    }

    node* root = &pool[1];

    int ans = cal(root);
    cout << '\n' << "정답 : " << ans;
}