#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

//너비 우선 bfs
int C, S, T;

void bfs(int x, int y, int cnt) {
    queue <pair <pair <int, int>, int>> q;
    q.push({{x, y}, cnt });

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (x > y) continue;
        if (x == y) {
            cout << cnt << "\n";
            break;
        }
        q.push({ {x * 2, y + 3}, cnt + 1 });
        q.push({ {x + 1, y}, cnt + 1 });
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> C;
    while (C--) {
        cin >> S >> T;
        bfs(S, T, 0);
    }
}

// 재귀
int C, S, T;

int recur(int s, int t, int cnt) {
    if (s > t) return 100;
    if (s == t) return cnt;
    else {
        int a = recur(s * 2, t + 3, cnt + 1);
        int b = recur(s + 1, t, cnt + 1);
        return min(a, b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> C;
    while (C--) {
        cin >> S >> T;
        cout << recur(S, T, 0) << "\n";
    }
}