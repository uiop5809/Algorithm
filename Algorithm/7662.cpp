#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int T, k, n;
char op;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		priority_queue<int> pq; // 내림차순
		priority_queue<int, vector<int>, greater<int>> pq1; // 올림차순
		map <int, int> m;

		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> op >> n;

			if (op == 'I') {
				pq.push(n);
				pq1.push(n);

				if (m.count(n) == 0) m[n] = 1;
				else m[n]++;
			}
			else if(op == 'D') {
				if (n == 1) {
					// 최소값으로 삭제된 거 skip
					while (!pq.empty() && m[pq.top()] == 0) pq.pop();
					if (!pq.empty()) {
						m[pq.top()]--;
						pq.pop();
					}
				}
				else if(n == -1) {
					// 최대값으로 삭제된 거 skip
					while (!pq1.empty() && m[pq1.top()] == 0) pq1.pop();
					if (!pq1.empty()) {
						m[pq1.top()]--;
						pq1.pop();
					}
				}
			}
		}
		while (!pq.empty() && m[pq.top()] == 0) pq.pop();
		while (!pq1.empty() && m[pq1.top()] == 0) pq1.pop();

		if (pq.empty() || pq1.empty()) cout << "EMPTY\n";
		else cout << pq.top() << " " << pq1.top() << "\n"; 
	}
}