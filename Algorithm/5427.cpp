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

int T, h, w, t;
char arr[1001][1001];
bool c[1001][1001];

queue <pair<int, int>> sq; //상근
queue <pair<int, int>> fq; //불

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool bfs() {
    t = 0;
    while (!sq.empty()) {
        int fqsize = fq.size();
        int sqsize = sq.size();
        t++;

        while (fqsize--) { //불 이동
            int x = fq.front().first;
            int y = fq.front().second;
            fq.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 1 || ny < 1 || nx > h || ny > w) 
                    continue;
                if (arr[nx][ny] != '#' && !c[nx][ny]) {
                    fq.push({ nx,ny });
                    c[nx][ny] = 1;
                }
            }
        }

        while (sqsize--) {  //상근이 이동
            int x = sq.front().first;
            int y = sq.front().second;
            sq.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 1 || ny < 1 || nx > h || ny > w) {
                    return 1;
                }
                if (arr[nx][ny] != '#' && !c[nx][ny]) {
                    sq.push({ nx,ny });
                    c[nx][ny] = 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> T;
    while (T--) {
        cin >> w >> h;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '@') {
                    sq.push({ i,j });
                    arr[i][j] = '.';
                    c[i][j] = 1;
                }
                else if (arr[i][j] == '*') {
                    fq.push({ i,j });
                    c[i][j] = 1;
                }
            }
        }
        if (bfs()) cout << t << "\n";
        else cout << "IMPOSSIBLE" << "\n";

        memset(c, 0, sizeof(c));
        memset(arr, 0, sizeof(arr));
        while (!fq.empty()) fq.pop();
        while (!sq.empty()) sq.pop();
    }
    return 0;
}
