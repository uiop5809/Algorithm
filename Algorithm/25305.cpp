#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K, num[1001];
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N, greater<int>());
	cout << num[K - 1];
}