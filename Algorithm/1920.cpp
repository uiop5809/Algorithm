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

int N, M, n[100001], m[100001], res[100001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	sort(n, n + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> m[i];
	}

	for (int i = 0; i < M; i++) {
		res[i] = binary_search(n, n + N, m[i]);
	}

	for (int i = 0; i < M; i++) {
		cout << res[i] << "\n";
	}
}