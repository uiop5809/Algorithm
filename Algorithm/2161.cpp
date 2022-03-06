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

int main() {
	int N;
	cin >> N;

	queue <int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();

		if (!q.empty()) {
			q.push(q.front());
			q.pop();
		}
	}
}