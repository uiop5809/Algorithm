#include <iostream>
#include <algorithm>
using namespace std;

int K, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> K;
	for(int i = 1; i <= K; i++){
		cin >> N;
		int num[51];
		for (int j = 0; j < N; j++) {
			cin >> num[j];
		}
		sort(num, num + N);

		int res = 0;
		for (int j = N - 1; j > 0; j--) {
			res = max(res, num[j] - num[j - 1]);
		}
		cout << "Class " << i << "\n";
		cout << "Max " << num[N - 1] << ", Min " << num[0] << ", Largest gap " << res << "\n";
	}
}