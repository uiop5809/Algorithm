#include <iostream>
#include <algorithm>
using namespace std;

int N, num[1001], dp[1001];

void dynamic() {
	dp[1] = num[1];
	int res = dp[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = num[i];
		for (int j = 1; j < i; j++) {
			if (num[j] < num[i]) {
				dp[i] = max(dp[i], dp[j] + num[i]);
			}
		}
		res = max(res, dp[i]);
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	dynamic();
}