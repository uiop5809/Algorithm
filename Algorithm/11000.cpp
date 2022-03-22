#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>
#include <cmath>
#include <climits>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N, S, T;
vector <pair<int, int>> v(N);

priority_queue <int, vector<int>, greater<int>> pq;

void lecture() {
    pq.push(v[0].second);

    for (int i = 1; i < N; i++) {
        pq.push(v[i].second);
        if (pq.top() <= v[i].first) pq.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S >> T;
        v.push_back({ S, T });
    }

    sort(v.begin(), v.end());
    lecture();
    cout << pq.size();
}