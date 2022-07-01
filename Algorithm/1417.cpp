#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, dasom, num, cnt = 0;
	cin >> N >> dasom;
	priority_queue<int> pq;
	for (int i = 1; i < N; i++) {
		cin >> num;
		if (num >= dasom) pq.push(num);
	}
	while (!pq.empty() && pq.top() >= dasom) {
		int now = pq.top();
		pq.pop();
		now--; dasom++;
		pq.push(now);
		cnt++;
	}
	cout << cnt;
	return 0;
}