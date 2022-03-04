#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int arr[101][101];
int c[101][101];
int N, M, cnt;

queue <pair<int, int>> q;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(int a, int b) {
    q.push({ a, b });
    c[a][b]++;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || nx > N || ny <= 0 || ny > M) 
                continue;
            if (c[nx][ny] == 0 && arr[nx][ny] == 1) {
                c[nx][ny] = c[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    bfs(1, 1);
    cout << c[N][M] << '\n';

    return 0;
}