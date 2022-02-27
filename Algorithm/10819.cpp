#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	vector <int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int result = 0;
	do {
		int temp = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			temp += abs(v[i] - v[i + 1]);
		}
		result = max(result, temp);
	} while (next_permutation(v.begin(), v.end()));

	cout << result;
}