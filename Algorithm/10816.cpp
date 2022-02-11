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

typedef long long ll;

ll N, M;
ll n[500001], m[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	sort(n, n + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> m[i];

		cout << upper_bound(n, n+N, m[i]) - lower_bound(n, n+N, m[i]) << " ";
	}
}