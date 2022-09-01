#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N, M;
int parent[201], travel[1001];
bool res = true;

// 부모 노드를 찾는 함수
int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

// 두 부모 노드를 작은 것으로 합치는 함수
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

// 부모 노드가 같은지 확인하는 함수
void findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b) res = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N;i++) {
		parent[i] = i;
	}

	int num;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num;
			if (num == 1) unionParent(i, j);
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> travel[i];
	}
	for(int i = 0; i < M - 1; i++){
		findParent(travel[i], travel[i + 1]);
	}
	if (res) cout << "YES";
	else cout << "NO";
}