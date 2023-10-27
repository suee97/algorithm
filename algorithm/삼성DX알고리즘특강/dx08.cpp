#include <iostream>
#include <sstream>
using namespace std;

struct node {
    char key;
    node* left;
    node* right;
};

string getWord(node* root) {
    string s = "";
    if (root->left) {
        s += getWord(root->left);
    }
    s += root->key;
    if (root->right) {
        s += getWord(root->right);
    }

    return s;
}

int main() {
    string n;
    getline(cin, n);

    node pool[101];

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

    string ans = getWord(root);
    cout << ans;

}