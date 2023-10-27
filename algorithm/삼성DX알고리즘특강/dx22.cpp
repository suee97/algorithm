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
		printf("#%d %d\n", tc, run());
	}
	return 0;
}


#include <iostream>
using namespace std;

/* USER CODE */
int nodeNum;
int lastIdx;
pair<int, int> nodes[100001];

void init()
{
    nodeNum = 1;
    for (int i = 0; i < 100001; i++) {
        nodes[i].first = -1;
        nodes[i].second = -1;
    }
}

void addUser(int uID, int height) 
{
    lastIdx = uID + 1;
    int id = uID + 1;
    if (id == 1) {
        nodes[1] = {1, height};
        return;
    }
    nodes[id] = {id, height};
    
    int curIdx = id;
    while (1) {
        if (curIdx == 1) break;
        if (nodes[curIdx/2].second > nodes[curIdx].second) break;
        pair<int, int> tmp = nodes[curIdx];
        nodes[curIdx] = nodes[curIdx/2];
        nodes[curIdx/2] = tmp;
        curIdx = curIdx/2;
    }
    
}

int getTop10(int result[10]) 
{
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (nodes[1].first == -1) {
            break;
        }
        result[i] = nodes[1].first;
        nodes[1].first = -1; nodes[1].second = -1;
        cnt++;

        // 삭제
        nodes[1].first = nodes[lastIdx].first;
        nodes[2].second = nodes[lastIdx].second;
        nodes[lastIdx].first = nodes[lastIdx].second = -1;
        lastIdx--;
        
        int curIdx = 1;
        while (1) {
            // 맨아래까지 간 경우
            if (nodes[curIdx*2].first == -1 && nodes[curIdx*2+1].first == -1) {
                break;
            }
            // 왼쪽 노드밖에 없는 경우
            if (nodes[curIdx*2].first != -1 && nodes[curIdx*2+1].first == -1) {
                if (nodes[curIdx*2].second > nodes[curIdx].second) {
                    pair<int, int> tmp = nodes[curIdx];
                    nodes[curIdx] = nodes[curIdx*2];
                    nodes[curIdx*2] = tmp;
                    break;
                }
            }
            // 두 노드 모두 있는 경우
            if (nodes[curIdx].second > nodes[curIdx*2].second 
                && nodes[curIdx].second > nodes[curIdx*2+1].second) {
                    break;
                }
            
            if (nodes[curIdx*2].second > nodes[curIdx*2+1].second) {
                pair<int, int> tmp = nodes[curIdx];
                nodes[curIdx] = nodes[curIdx*2];
                nodes[curIdx*2] = tmp;
                curIdx = curIdx*2;
            } else {
                pair<int, int> tmp = nodes[curIdx];
                nodes[curIdx] = nodes[curIdx*2+1];
                nodes[curIdx*2+1] = tmp;
                curIdx = curIdx*2+1;
            }
        }
        
    }
    return cnt;
}