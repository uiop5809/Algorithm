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

	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;

	int first = m;
	int time = 0;

	if (m + T > M) {
		cout << -1;
		return 0;
	}

	while (1) {
		if (first + T <= M) {
			first += T;
			N--;
		}
		else {
			first -= R;
			if (first < m) first = m;
			// first - R이 m보다 작으면 맥박은 m이 된다.
		}
		time++;
		if (N == 0) break;
	}
	cout << time;
}