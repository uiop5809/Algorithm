#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K, A, B;
int arr[101][101];
const int INF = 1e9;

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> A >> B;
		arr[A][B] = 1;
		arr[B][A] = 1;
	}
	floyd();

	bool flag = true;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] > 6) cnt++;
		}
		if (cnt > 0) flag = false;
	}
	if (flag) cout << "Small World!";
	else cout << "Big World!";
}