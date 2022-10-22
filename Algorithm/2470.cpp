#include <iostream>
#include <algorithm>
using namespace std;

int N, num[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);

	int start = 0, end = N - 1;
	int res = 2e9 + 1, res1, res2;
	while (start < end) {
		if (abs(num[start] + num[end]) < res) {
			res = abs(num[start] + num[end]);
			res1 = num[start];
			res2 = num[end];
		}
		if (num[start] + num[end] > 0) {
			end--;
		}
		else {
			start++;
		}
	}
	cout << res1 << " " << res2;
}