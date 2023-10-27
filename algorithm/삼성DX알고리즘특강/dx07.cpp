#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

extern void init();
extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern int findNode(int data);
extern void removeNode(int data);
extern int getList(int output[MAX_NODE]);
extern int getReversedList(int output[MAX_NODE]);

static void run() {
	while (1) {
		int cmd, data, num, cnt, i = 0;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD: // 1
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL: // 2
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM: // 3
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case FIND: // 4
			scanf("%d", &data);
			num = findNode(data);
			printf("%d\n", num);
			break;
		case REMOVE: // 5
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT: // 6
			cnt = getList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case PRINT_REVERSE: // 7
			cnt = getReversedList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

int main(void) {
	setbuf(stdout, NULL);
	freopen("dx07_data.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		init();
		run();
		printf("\n");
	}

	return 0;
}


////////////////////////////////
// USER CODE
////////////////////////////////
#include <iostream>
#define MAX_NODE 10000
using namespace std;

void show();

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node nodes[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	nodes[nodeCnt].data = data;
	nodes[nodeCnt].prev = nullptr;
	nodes[nodeCnt].next = nullptr;
	return &nodes[nodeCnt++];
}

void init()
{
    cout << "init()" << '\n';
    Node* tmp = new Node;
    tmp->prev = nullptr;
    tmp->next = nullptr;
    tmp->data = -1;
    head = tmp;
}

void addNode2Head(int data) 
{
    cout << "addNode2Head()  " << "data is " << data << '\n';
    Node* tmp = getNode(data);
    tmp->next = head->next;
    tmp->prev = head;
    head->next = tmp;
    if (tmp->next) tmp->next->prev = tmp;
}

void addNode2Tail(int data) 
{
    cout << "addNode2Tail()    " << "data is " << data << '\n';
    Node* tmp = getNode(data);
    Node* cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = tmp;
    tmp->prev = cur;
}

void addNode2Num(int data, int num) 
{
    cout << "addNode2Num()  " << "data is " << data << "  num is " << num << '\n';

    Node* tmp = getNode(data);
    Node* cur = head;

    for (int i = 0; i < num-1; i++) {
        cur = cur->next;
    }

    tmp->next = cur->next;
    if (cur->next != nullptr) cur->next->prev = tmp;        
    cur->next = tmp;
    tmp->prev = cur;

}

int findNode(int data) // 순서
{
    cout << "findNode()" << '\n';
    int cnt = 0;
    Node* cur = head;
    while (cur) {
        if (cur->data == data) {
            break;
        } else {
            cur = cur->next;
            cnt++;
        }
    }

    return cnt;
}

void removeNode(int data) 
{
    cout << "removeNode()    " << "data is " << data << '\n';
    Node* cur = head;
    while (cur) {
        if (cur->data == data) {
            if (cur->next == nullptr) {
                cur->prev->next = nullptr;
            } else {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            break;
        } else {
            cur = cur->next;
        }
    }
}

int getList(int output[MAX_NODE]) 
{
    cout << "getList()" << '\n';
    int cnt = 0;
    Node* cur = head;
    while (cur->next) {
        cur = cur->next;
        output[cnt++] = cur->data;
    }
    return cnt;
}

int getReversedList(int output[MAX_NODE]) 
{
    cout << "getReversedList()" << '\n';
    int cnt = 0;
    Node* cur = head;

    while (cur->next) {
        cur = cur->next;
    }

    while (cur != head) {
        output[cnt++] = cur->data;
        cur = cur->prev;
    }

    return cnt;
}

void show()
{
    Node* cur = head;
    cout << "[ ";
    while (cur->next) {
        cur = cur->next;
        cout << cur->data << ' ';
    }
    cout << " ]\n";
}