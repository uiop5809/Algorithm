#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;
#define INF 1000000000000

long long N, M, K, u, v, c;
long long dist[100001];

vector <long long> num;
vector <pair <int, int>> edge[100001];

priority_queue <pair <int, int>> pq;

void dijkstra() {
    long long max = 0;
    for (int i = 0; i < K; i++) {
        pq.push({ 0, num[i]});
        dist[num[i]] = 0;
    }

    while (!pq.empty()) {
        long long cost = -pq.top().first;
        long long now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) continue;
        for (int i = 0; i < edge[now].size(); i++) {
            long long next = edge[now][i].first;
            long long nextcost = edge[now][i].second;

            if (dist[next] > dist[now] + nextcost) {
                dist[next] = dist[now] + nextcost;
                pq.push({ -dist[next], next});
            }
        }
    }

    int index = 0;
    for (int i = 1; i <= N; i++) {
        if (max < dist[i]) {
            index = i;
            max = dist[i];
        }
    }
    cout << index << "\n" << max << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> c;
        edge[v].push_back({ u, c });
    }
    for (int i = 0; i < K; i++) {
        cin >> u;
        num.push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dijkstra();
}