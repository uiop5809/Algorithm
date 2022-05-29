#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[1000001];

int dynamic(int n) {
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2]);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3]);
		}
		dp[i] = min(dp[i], dp[i - 1]) + 1;
	}
	return dp[n] - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	cout << dynamic(N) << "\n";

	while (N != 0) {
		cout << N << " ";
		if (dp[N] == dp[N - 1] + 1) {
			N -= 1;
		}
		else if (N % 2 == 0 && dp[N] == dp[N / 2] + 1) {
			N /= 2;
		}
		else if (N % 3 == 0 && dp[N] == dp[N / 3] + 1) {
			N /= 3;
		}
	}
}