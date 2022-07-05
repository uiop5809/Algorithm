#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, arr[101][101];
bool c[21];
int res = 1e9;

void dfs(int cnt, int num) {
	// 카운트수가 정원의 1/2 됐을 때 능력치합 계산
	if (cnt == N / 2) { 
		int start = 0, link = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (c[i] && c[j]) start += arr[i][j];
				if (!c[i] && !c[j]) link += arr[i][j];
			}
		}
		int temp = abs(start - link);
		res = min(res, temp);
		return;
	}
	for (int i = num; i < N; i++) {
		c[i] = true;
		dfs(cnt + 1, i + 1);
		c[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 1);
	cout << res;
}