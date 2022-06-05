#include <iostream>
using namespace std;

int N, P[1001], dp[1001];
// P[i] = 카드 i개의 가격
// dp[i] = i개 카드를 구매했을 때의 최대비용

int dynamic() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + P[j]);
		}
	}
	return dp[N];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	cout << dynamic();
}