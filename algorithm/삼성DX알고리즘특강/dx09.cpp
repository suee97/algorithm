#include <iostream>
#include <sstream>
using namespace std;

bool isFail = false;

struct node {
    int key;
    node* left;
    node* right;
};

int getWord(node* root) {
    int leftOp;
    int rightOp;
    int res;

    // Child가 하나인 경우
    if ((root->left && !root->right) || (!root->left && root->right)) {
        isFail = true;
        return 1;
    }
    
    // 마지막 노드인 경우
    if (!root->left && !root->right) {
        // 마지막노드에 숫자가 오지 않은 경우

        int tmp = root->key;
        return tmp;
    }

    if (root->left) {
        leftOp = getWord(root->left);
    }
    if (root->right) {
        rightOp = getWord(root->right);
    }
    
    if (root->key == '+') {
        return leftOp + rightOp;
    } else if (root->key == '/') {
        return leftOp / rightOp;
    } else if (root->key == '-') {
        return leftOp - rightOp;
    } else if (root->key == '*') {
        return leftOp * rightOp;
    } else { // key에 연산자를 제외한 것이 들어간 경우
        isFail = true;
        return 1;
    }

    return res;
}

int main() {
    string n;
    getline(cin, n);

    node pool[201];

    string tmp;

    for (int i = 0; i < stoi(n); i++) {
        int idx; char value; int left; int right;

        getline(cin, tmp);
        stringstream ss;
        string splited;
        ss.str(tmp);
        int cnt = 0;
        while (ss >> splited) {
            if (cnt == 0) {
                idx = stoi(splited);
            } else if (cnt == 1) {
                value = splited[0];
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

    int ans = getWord(root);
    if (isFail) {
        cout << 0;
    } else {
        cout << 1;
    }
    isFail = false;
}