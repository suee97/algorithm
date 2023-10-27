#include <iostream>
using namespace std;

struct node {
    string val;
    node* next;
};

int main() {
    int n;
    cin >> n;

    node* pool = new node[n];

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        node tmp;
        tmp.val = s;
        pool[i] = tmp;
    }

    for (int i = 0; i < n-1; i++) {
        pool[i].next = &pool[i+1];
    }
    pool[n-1].next = NULL;
    node* head = &pool[0];

    // 명령어
    int m;
    cin >> m;

    while (m--) {
        char input;
        cin >> input;
        
        if (input == 'I') {
            // pointer 이동
            int x, y;
            cin >> x >> y;
            int after = x;
            node* cur = head;
            if (x != 0) x -= 1;

            while (x--) {
                cur = cur->next;
            }

            // 삽입 연산
            node* tmpArr = new node[y];
            for (int i = 0; i < y; i++) {
                string s;
                cin >> s;
                node tmpNode;
                tmpNode.val = s;
                tmpArr[i].val = s;
            }

            for (int i = 0; i < y-1; i++) {
                tmpArr[i].next = &tmpArr[i+1];
            }

            if (after == 0) {
                tmpArr[y-1].next = head;
                head = &tmpArr[0];
                continue;
            }

            if (cur->next == NULL) {
                tmpArr[y-1].next = NULL;
                cur->next = &tmpArr[0];
                continue;
            }

            tmpArr[y-1].next = cur->next;
            cur->next = &tmpArr[0];
        }

        if (input == 'D') {
            int x, y;
            cin >> x >> y;
            node* cur = head;
            int after = x;
            if (x != 0) x -= 1;
            while (x--) {
                cur = cur->next;
            }

            if (after == 0) {
                for (int i = 0; i < y; i++) {
                    head = head->next;
                }
                continue;
            }
            
            node* daum = cur;
            for (int i = 0; i < y; i++) {
                daum = daum->next;
            }

            if (daum->next == NULL) {
                cur->next = NULL;
            } else {
                cur->next = daum->next;
            }
        }

        if (input == 'A') {
            node* cur = head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            int y; cin >> y;
            node* tmp = new node[y];
            for (int i = 0; i < y; i++) {
                string s;
                cin >> s;
                node tmpNode;
                tmpNode.val = s;
                tmp[i] = tmpNode;
            }
            for (int i = 0; i < y-1; i++) {
                tmp[i].next = &tmp[i+1];
            }
            tmp[y-1].next = NULL;
            cur->next = &tmp[0];
        }

        // 명령어 이후 출력
        cout << input << " 명령 이후 : ";
        node* cur = head;
        while (cur != NULL) {
            cout << cur->val << ' ';
            cur = cur->next;
        }
        cout << '\n';
    }

    // 암호문 10개 출력
    node* cur = head;
    for (int i = 0; i < 10; i++) {
        cout << cur->val << ' ';
        cur = cur->next;
    }

}