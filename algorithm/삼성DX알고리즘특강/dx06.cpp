#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99 };

extern void init();
extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern void removeNode(int data);
extern int getList(int output[MAX_NODE]);

static void run() {
	while (1) {
		int cmd, data, num, cnt, i;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD:
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL:
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM:
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case REMOVE:
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT:
			cnt = getList(output);
			i = 0;
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
	freopen("dx06_data.txt", "r", stdin);

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

////////////////////////////
// user code
////////////////////////////
using namespace std;
#include <iostream>
#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node nodes[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	nodes[nodeCnt].data = data;
	nodes[nodeCnt].next = nullptr;
	return &nodes[nodeCnt++];
}

void init()
{   
    cout << "init()" << '\n';
    Node* tmp = new Node;
    tmp->data = -1;
    tmp->next = nullptr;
    head = tmp;
}

void addNode2Head(int data) 
{
    cout << "맨 앞 추가" << '\n';
    Node* tmp = getNode(data);
    tmp->next = head->next;
    head->next = tmp;
}

void addNode2Tail(int data) 
{
    cout << "맨 뒤 추가" << '\n';
    Node* cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    Node* tmp = getNode(data);
    cur->next = tmp;
}

void addNode2Num(int data, int num) 
{
    cout << "중간 추가" << '\n';
    Node* tmp = getNode(data);
    Node* cur = head;
    for (int i = 0; i < num-1; i++) {
        cur = cur->next;
    }
    tmp->next = cur->next;
    cur->next = tmp;
}

void printAll() {
    cout << "printAll()" << '\n';
    Node* cur = head;
    while (cur) {
        cout << cur->data << ' ';
        cur = cur->next;
    }
    cout << '\n';
}

void removeNode(int data) 
{
    cout << "removeNode()" << '\n';
    printAll();
    Node* cur = head;
    while (cur) {
        if (cur->next == nullptr) break;
        if (cur->next->data == data) {
            cur->next = cur->next->next;
            break;
        }
        cur = cur->next;
    }
}

int getList(int output[MAX_NODE]) 
{
    cout << "getList()" << '\n';
    Node* cur = head->next;
    int cnt = 0;
    while (cur) {
        output[cnt++] = cur->data;
        cur = cur->next;
    }
    return cnt;
}