#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

void bfs_init(int N, int map[10][10]);
int bfs(int x1, int y1, int x2, int y2);

static int test_bfs() {
	int N;
	int map[10][10];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	bfs_init(N, map);
	int M;
	int score = 100;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int result = bfs(x1, y1, x2, y2);
		int dist;
		scanf("%d", &dist);
		if (result != dist) score = 0;
	}
	return score;
}

int main() {
	setbuf(stdout, NULL);

	printf("#total score : %d\n", test_bfs());

	return 0;
}


/* USER CODE */
#include <iostream>
using namespace std;

int board[10][10];
int dist[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;

void bfs_init(int map_size, int map[10][10]) {
    cout << "bfs_init()" << '\n';
    n = map_size;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = map[i][j];
        }
    }
}

struct paire {
    int x;
    int y;
};

int bfs(int x1, int y1, int x2, int y2) {

    int st_x = y1-1;
    int st_y = x1-1;
    int end_x = y2-1;
    int end_y = x2-1;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            dist[i][j] = -1;
        }
    }

    dist[st_x][st_y] = 0;

    paire tmp; tmp.x = st_x; tmp.y = st_y;
    paire q[1000];
    q[0] = tmp;
    int l = 0; // out 하는 인덱스
    int r = 1; // input 하는 Index

    while (l != r) {
        paire cur = q[l];
        l++;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                paire tmp; tmp.x = nx; tmp.y = ny;
                q[r++] = tmp;
            }
        }
    }
    return dist[end_x][end_y];
}