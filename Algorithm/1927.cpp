#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N, x;

priority_queue <int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	while (N--) {
		cin >> x;
		if (!x) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else cout << "0\n";
		}
		else {
			pq.push(x);
		}
	}
}