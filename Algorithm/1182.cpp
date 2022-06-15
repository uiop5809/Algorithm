#include <iostream>
using namespace std;

int N, S, num[21], res;

void dfs(int sum, int input) {
	if (sum == S && input != 0) res++;
	for (int i = input; i < N; i++) {
		dfs(sum + num[i], i + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	dfs(0, 0);
	cout << res;
}