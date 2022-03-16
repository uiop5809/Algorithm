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

int N, M, V, num[200001], quest;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> V;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	while (M--) {
		cin >> quest;

		if (quest < V) cout << num[quest + 1] << "\n";
		else cout << num[(quest - V + 1) % (N - V + 1) + V] << "\n";
	}
}