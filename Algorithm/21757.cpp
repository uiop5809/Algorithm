#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int N;
long long num[100001], preSum[100001];
long long dp[100001][5];

long long dynamic() {
	for (int i = 1; i <= N; i++) {
		preSum[i] = preSum[i - 1] + num[i];
	}

	// 4등분한 부분의 합이 같다면,
	// 4등분한 부분 수열의 합은 전체 수열의 합/4과 같다.
	long long sum = preSum[N] / 4;
	if (sum * 4 != preSum[N]) return 0;

	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= 3; j++) {
			dp[i][j] = dp[i - 1][j];
			if (sum * j == preSum[i]) dp[i][j] += dp[i - 1][j - 1];
		}
	}
	return dp[N - 1][3];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	cout << dynamic();
}