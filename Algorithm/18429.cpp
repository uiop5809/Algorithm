#include <iostream>
#include <vector>
using namespace std;

int N, K, num[9], res;
bool c[9];
vector<int> v;

void dfs(int cnt) {
	if (cnt == N) {
		int sum = 500;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
			sum -= K;
			if (sum < 500) return;
		}
		res++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (c[i]) continue;
		c[i] = true;
		v.push_back(num[i]);
		dfs(cnt + 1);
		c[i] = false;
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	dfs(0);
	cout << res;
}