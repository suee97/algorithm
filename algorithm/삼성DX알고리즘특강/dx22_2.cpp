#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_INPUT 10000
#define MAX_NUM 30000

extern void init();
extern void addUser(int uID, int income);
extern int getTop10(int result[10]);

static int input[MAX_INPUT];

static unsigned int seed = 13410;

static unsigned int pseudoRand() {
	seed = seed * 214013 + 2531011;
	return (unsigned int)(seed >> 11) % MAX_NUM;
}

static void makeInput(int inputLen) {
	for (int i = 0; i < inputLen; i++) {
		input[i] = pseudoRand();
	}
}

static int run() {
	int N, userNum, uID = 0;
	int score = 100, result[10], cnt;
	int sum, check;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &userNum);
		makeInput(userNum);
		for (int j = 0; j < userNum; j++) {
			addUser(uID++, input[j]);
		}
		cnt = getTop10(result);

		sum = 0;
		for (int j = 0; j < cnt; j++)
			sum += result[j];
		scanf("%d", &check);
		if (check != sum)
			score = 0;
	}
	return score;
}

int main(void) {
	setbuf(stdout, NULL);
	freopen("dx22_data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		init();
		printf("\n\n######## %d %d\n\n", tc, run());
	}
	return 0;
}

#include <iostream>
using namespace std;

struct node {
    int id;
    int height;
    node(int _id, int _height) : id(_id), height(_height) {};
    node() : id(-1), height(-1) {};
};

node* tree = new node[200002];
int tree_size;

void init()
{
    tree_size = 0;
    for (int i = 0; i < 200002; i++) {
        tree[i] = node(-1, -1);
    }

    cout << "### init() ###" << '\n';
}

void swap(int i1, int i2) {
    node tmp = tree[i1];
    tree[i1] = tree[i2];
    tree[i2] = tmp;
}

void addUser(int uID, int height) 
{
    // cout << "[ " << uID << ' ' << height << " ]";
    tree[++tree_size] = node(uID, height); // 1번 노드부터 취급
    int curIdx = tree_size;
    while (1) {
        if (curIdx == 1) break;
        if (tree[curIdx / 2].height > tree[curIdx].height) {
            break;
        } 
        else if (tree[curIdx / 2].height < tree[curIdx].height) {
            swap(curIdx, curIdx/2);
            curIdx /= 2;
        } 
        else {
            if (tree[curIdx / 2].id < tree[curIdx].id) {
                break;
            } 
            else {
                swap(curIdx, curIdx/2);
                curIdx /= 2;
            }
        }
    }
}

int getTop10(int result[10])
{   
    // cout << "\n전체 노드\n";
    // for (int i = 1; i <= tree_size; i++) {
    //     cout << "i : " << i << ' ' << tree[i].height << " || ";
    // }

    node tmpArr[10];

    int cnt = 0;
    // cout << "\ngetTop10 : ";
    for (int i = 0; i < 10; i++) {
        if (tree[1].height == -1) { // 비어있음
            break;
        }

        tmpArr[cnt++] = tree[1];
        // v.push_back(tree[1]);

        // result[i] = tree[1].id;
        // cout << "[ " << tree[1].id << ' ' << tree[1].height << " ]";

        tree[1] = tree[tree_size];
        tree[tree_size--] = node(-1, -1);

        // bubble down
        int curIdx = 1;
        while (1) {
            // 리프노드인 경우
            if (tree[curIdx*2].height == -1 && tree[curIdx*2+1].height == -1) {
                break;
            }

            // 왼쪽 노드만 있는 경우
            else if (tree[curIdx*2].height != -1 && tree[curIdx*2+1].height == -1) {
                if (tree[curIdx*2].height > tree[curIdx].height) {
                    swap(curIdx, curIdx*2);
                    curIdx *= 2;
                } else if (tree[curIdx*2].height < tree[curIdx].height) {
                    break;
                } else { // height 같은 경우
                    if (tree[curIdx*2].id > tree[curIdx].id) {
                        break;
                    } else {
                        node tmp = tree[curIdx];
                        tree[curIdx] = tree[curIdx*2];
                        tree[curIdx*2] = tmp;
                        curIdx *= 2;
                    }
                }
            } 
            
            // 왼쪽, 오른쪽 자식 모두 있음
            else if (tree[curIdx*2].height != -1 && tree[curIdx*2+1].height != -1) {
                node larger;
                int larger_idx;

                if (tree[curIdx*2].height > tree[curIdx*2+1].height) {
                    larger = tree[curIdx*2];
                    larger_idx = curIdx*2;
                } else if (tree[curIdx*2].height < tree[curIdx*2+1].height) {
                    larger = tree[curIdx*2+1];
                    larger_idx = curIdx*2+1;
                } else {
                    if (tree[curIdx*2].id < tree[curIdx*2+1].id) {
                        larger = tree[curIdx*2];
                        larger_idx = curIdx*2;
                    } else {
                        larger = tree[curIdx*2+1];
                        larger_idx = curIdx*2+1;
                    }
                }

                if (larger.height > tree[curIdx].height) {
                    swap(curIdx, larger_idx);
                    // node tmp = tree[curIdx];
                    // tree[curIdx] = larger;
                    // larger = tmp;
                    curIdx = larger_idx;
                } else if (larger.height < tree[curIdx].height) {
                    break;
                } else {
                    if (larger.id < tree[curIdx].id) {
                        // node tmp = tree[curIdx];
                        // tree[curIdx] = larger;
                        // larger = tmp;
                        swap(curIdx, larger_idx);
                        curIdx = larger_idx;
                    } else {
                        break;
                    }
                }
            } else {
                break;
            }
        }
    }

    if (cnt >= 2) {
        int swap_count;
        int l = 0, r = 1;

        while (1) {
            swap_count = 0;
            while (l != cnt) {
                if (tmpArr[l].height == tmpArr[r].height) {
                    if (tmpArr[l].id > tmpArr[r].id) {
                        node tmp = tmpArr[l];
                        tmpArr[l] = tmpArr[r];
                        tmpArr[r] = tmp;
                        swap_count++;
                    }
                }
                l++; r++;
            }
            if (!swap_count) break;
        }
    }

    cout << '\n';
    for (int i = 0; i < cnt; i++) {
        result[i] = tmpArr[i].id;
        addUser(tmpArr[i].id, tmpArr[i].height);
        cout << "[ " << tmpArr[i].id << ' ' << tmpArr[i].height << " ]";
    }

    return cnt < 10 ? cnt : 10;
}