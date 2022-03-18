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

int n, m, x, y, z, from, to;
const int INF = 1e9;

int res[1001];

vector <int> dist;
vector <pair <int, int>> edge[1001];

priority_queue <pair <int, int>> pq;

void dijkstra() {
    dist.resize(n + 1, INF);
    dist[from] = 0;
    pq.push({ 0, from }); // 가중치, 시작정점

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
                res[next] = now;
                pq.push({ -dist[next], next });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        edge[x].push_back({ y, z }); // 이웃노드, 가중치
    }
    cin >> from >> to;
    dijkstra();

    vector <int> ans;
    int temp = to;
    while (temp) {
        ans.push_back(temp);
        temp = res[temp];
    }

    cout << dist[to] << "\n";
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
}