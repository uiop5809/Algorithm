#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int K;
vector<int> v;
vector<int> res[11];

void dfs(int start, int end, int depth) {
	if (start == end) {
		res[depth].push_back(v[start]);
		return;
	}
	// 완전 이진 트리, 중위 순회
	int mid = (start + end) / 2;
	res[depth].push_back(v[mid]);

	// root를 제외하고 좌우 탐색
	dfs(start, mid - 1, depth + 1);
	dfs(mid + 1, end, depth + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> K;
	for (int i = 0; i < pow(2, K) - 1; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	dfs(0, v.size() - 1, 0);

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}