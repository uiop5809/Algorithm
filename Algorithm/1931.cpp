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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector <pair <int, int>> num(N);

	for (int i = 0; i < N; i++) {
		cin >> num[i].second >> num[i].first;
	}

	int time = 0, cnt = 0;
	sort(num.begin(), num.end());
	for (int i = 0; i < N; i++) {
		if (time <= num[i].second) {
			time = num[i].first;
			cnt++;
		}
	}
	cout << cnt;
}