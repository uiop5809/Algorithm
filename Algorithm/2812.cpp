#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	string num;
	cin >> N >> K >> num;

	int idx = 0;
	for (int i = 0; i < N - K; i++) {
		int n = 0;
		for (int j = idx; j <= K + i; j++) {
			if (n < num[j] - '0') {
				n = num[j] - '0';
				idx = j + 1;
			}
		}
		cout << n;
	}
}