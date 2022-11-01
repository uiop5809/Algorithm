#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	queue <int> q;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) q.push(i);
	}
	if (q.size() < K) cout << 0;
	else {
		for (int i = 0; i < K - 1; i++) {
			q.pop();
		}
		cout << q.front();
	}
}