#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
};

int main() {
    int test_case;
	int T;
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, m, l;
        cin >> n >> m >> l;

        node pool[2100];
        int nodeCnt = 0;

        for (int i = 0; i < n; i++) {
            int inputVal;
            cin >> inputVal;

            pool[nodeCnt].val = inputVal;
            if (i == n-1) {
                pool[nodeCnt].next = nullptr;
            } else {
                pool[nodeCnt].next = &pool[nodeCnt+1];
            }
            nodeCnt++;
        }

        node hNode;
        hNode.next = &pool[0];
        hNode.val = -1;
        node* head = &hNode;

        while (m--) {
            char act;
            cin >> act;

            if (act == 'I') {
                int x, y;
                cin >> x >> y;

                node* left; node* right;
                left = head;
                right = head->next;

                for (int i = 0; i < x; i++) {
                    right = right->next;
                    left = left->next;
                }
                
                pool[nodeCnt].val = y;
                pool[nodeCnt].next = right;
                left->next = &pool[nodeCnt++];
            }

            if (act == 'D') {
                int x;
                cin >> x;

                node* left; node* right;
                left = head;
                right = head->next;

                for (int i = 0; i < x; i++) {
                    right = right->next;
                    left = left->next;
                }

                left->next = right->next;
            }

            if (act == 'C') {
                int x, y;
                cin >> x >> y;

                node* cur = head;
                for (int i = 0; i < x+1; i++) {
                    cur = cur->next;
                }

                cur->val = y;
            }
        }

        node* p = head;
        bool isNull = false;
        for (int i = 0; i < l+1; i++) {
            if (p->next != nullptr) {
                p = p->next;
            } else {
                isNull = true;
                break;
            }
        }

        cout << '#' << test_case << ' ';
        if (isNull) {
            cout << -1 << '\n';
        } else {
            cout << p->val << '\n';
        }

	}

	return 0;
}