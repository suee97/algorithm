#include <iostream>
using namespace std;

struct node {
    int val;
    node* prev;
    node* next;
};

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    
    node* mem = new node;
    node* head = new node;
    for (int i = 0; i < n; i++) {
        int inputVal;
        cin >> inputVal;
        
        if (i == 0) {
            node* new_node = new node;
            new_node->val = inputVal;
            head = new_node;
            new_node->prev = nullptr;
            new_node->next = nullptr;
            mem = new_node;
        } else if (i == n-1) {
            node* new_node = new node;
            new_node->val = inputVal;
            mem->next = new_node;
            new_node->prev = mem;
            mem = new_node;
            new_node->next = nullptr;
        } else {
            node* new_node = new node;
            new_node->val = inputVal;
            mem->next = new_node;
            new_node->prev = mem;
            mem = new_node;
        }
    }

    while (m--) {
        char input;
        cin >> input;
        
        if (input == 'I') {
            int x, y;
            cin >> x >> y;

            if (x == 0) {
                node* new_node = new node;
                new_node->val = y;
                new_node->next = head;
                new_node->prev = nullptr;
                head->prev = new_node;
                head = new_node;
                continue;
            }

            node* cur = head;
            for (int i = 0; i < x; i++) cur = cur->next;

            node* new_node = new node;
            new_node->val = y;
            new_node->next = cur;
            new_node->prev = cur->prev;
            cur->prev->next = new_node;
            cur->prev = new_node;
        }

        if (input == 'D') {
            int x;
            cin >> x;

            node* cur = head;

            for (int i = 0; i < x; i++) cur = cur->next;

            if (x == 0) {
                node* tmp = head;
                head = head->next;
                delete tmp;
                continue;
            }

            if (cur->next == nullptr) {
                node* tmp = cur;
                cur->prev->next = nullptr;
                delete tmp;
                continue;
            }
            
            node* tmp = cur;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete tmp;
        }

        if (input == 'C') {
            int x, y;
            cin >> x >> y;
            node* cur = head;
            for (int i = 0; i < x; i++) cur = cur->next;
            cur->val = y;
        }
    }

    cout << "전체 수열 (최종)" << '\n' << "[ ";
    node* it = head;
    while (it != nullptr) {
        cout << it->val << ' ';
        it = it->next;
    }
    cout << "]" << '\n';

    node* p = head;
    int isNull = 0;

    for (int i = 0; i < l; i++) {
        p = p->next;
        if (p == nullptr) {
            isNull = 1;
            break;
        }
    }
    if (isNull == 1 || p == nullptr) {
        cout << -1 << '\n';
    } else {
        cout << p->val << '\n';
    }


    // free all
    if (head == nullptr) {

    } else if (head->next == nullptr) {
        delete head;
    } else {
        node* rr = head->next;
        node* ll = head;
        while (rr) {
            delete ll;
            ll = rr;
            rr = rr->next;
        }
    }

}