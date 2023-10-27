#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

static unsigned int seed = 12345;
static unsigned int pseudo_rand(int max) {
	seed = ((unsigned long long)seed * 1103515245 + 12345) & 0x7FFFFFFF;
	return seed % max;
}

#define MAX_N (40)
#define MAX_K (98)
#define MIN_N (2)
#define MAX_CHILD (5)

extern void dfs_init(int N, int path[MAX_N][2]);
extern int dfs(int k);

static int p[MAX_K+2];
static int c[MAX_K+2];
static int path[MAX_N][2];
static void makeTree(int n) {
	for (int i = 1; i < MAX_K+2; ++i) {
		p[i] = c[i] = -1;
	}
	c[pseudo_rand(MAX_K + 1) + 1] = 0;
	for (int i = 0; i < n; ++i) {
		int pi = pseudo_rand(MAX_K + 1) + 1;
		while (c[pi] < 0 || c[pi] >= MAX_CHILD) {
			++pi;
			if (pi == MAX_K + 2)
				pi = 1;
		}
		int ci = pseudo_rand(MAX_K + 1) + 1;
		while (c[ci] >= 0) {
			++ci;
			if (ci == MAX_K + 2)
				ci = 1;
		}
		p[ci] = pi;
		++c[pi];
		c[ci] = 0;
	}
	bool check[MAX_K + 2] = { false };
	for (int i = 0; i < n; ++i) {
		int e = pseudo_rand(MAX_K + 1) + 1;
		while (check[e] || c[e] < 0 || p[e] == -1) {
			++e;
			if (e == MAX_K + 2)
				e = 1;
		}
		check[e] = true;
		path[i][0] = p[e];
		path[i][1] = e;
	}
}

int main() {
	setbuf(stdout, NULL);
	int T;
	freopen("dx13_data.txt", "r", stdin);
	scanf("%d", &T);

	int totalScore = 0;
	for (int tc = 1; tc <= T; tc++) {
		int n, q;

		scanf("%d %d %d", &n, &q, &seed);

		makeTree(n - 1);
		dfs_init(n, path);

		bool check[MAX_K + 2] = { false };
		int score = 100;
		for (int i = 0; i < q; ++i) {
			int k, ret, correct;

			scanf("%d", &k);

			ret = dfs(k);

			scanf("%d", &correct);

			if (ret != correct)
				score = 0;
		}
		printf("#%d : %d\n", tc, score);
		totalScore += score;
	}
	printf("#total score : %d\n", totalScore / T);
	return 0;
}


/* USER CODE */
#include <iostream>
using namespace std;
int board[100][100];
int vis[100];

int res, cnt;
int king;

struct node {
	int val;
	node* next;
};

node arr[100];
node pool[10000];
int nodeCnt = 0;

void dfs_init(int N, int path[100][2])
{
    cout << "\nN : " << N << '\n';

	for (int i = 0; i < 100; i++) {
		arr[i].next = nullptr;
	}

    for (int i = 0; i < N-1; i++) {
		node* cur = &arr[path[i][0]];
		while (cur->next) {
			cur = cur->next;
		}
		pool[nodeCnt].next = nullptr;
		pool[nodeCnt].val = path[i][1];
		cur->next = &pool[nodeCnt++];
        cout << "[ " << path[i][0] << "->" << path[i][1] << " ]";
    }
    cout << '\n';
}

void DFS(int n) {
    if (n > king && cnt == 0) {
        res = n;
        cnt++;
    }

	node* cur = arr[n].next;
	while (cur) {
		if(!vis[cur->val]) {
			vis[cur->val] = 1;
			DFS(cur->val);
		}
		cur = cur->next;
	}
}

int dfs(int n)
{
    res = -1;
    cnt = 0;
    for (int i = 0; i < 100; i++) vis[i] = 0;

    king = n;

    cout << "[ n : " << n << " 일때 ";

	DFS(n);
    if (res == -1) {
        cout << -1;
        cout << " ] ";
        return -1;
    } else {
        cout << res;
        cout << " ] ";
        return res;
    }
}