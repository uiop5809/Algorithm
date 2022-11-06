#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, num[1001], sum = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> num[i];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (i % num[j] == 0) {
				sum += i;
				break;
			}
		}
	}
	cout << sum;
}