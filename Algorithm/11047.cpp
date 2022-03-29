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

int N, K;
int coin[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	int sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		sum += K / coin[i];
		K = K % coin[i];
	}
	cout << sum;
}