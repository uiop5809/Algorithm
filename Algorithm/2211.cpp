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

int ans[1010];
int n, m, a, b, c;
const int INF = 1e9;

vector <int> dist;
vector <pair <int, int>> edge[1001];

priority_queue <pair <int, int>> pq;

void dijkstra() {
    dist.resize(n + 1, INF);
    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) continue;
        for (int i = 0; i < edge[now].size(); i++) {
            int next = edge[now][i].first;
            int nextcost = edge[now][i].second;

            if (dist[next] > dist[now] + nextcost) {
                dist[next] = dist[now] + nextcost;
                ans[next] = now;
                pq.push({ -dist[next], next });
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({ b, c });
        edge[b].push_back({ a, c });
    }
    dijkstra();

    cout << n - 1 << "\n";
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << " " << i << "\n";
    }
}