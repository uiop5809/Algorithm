#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, num[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	int sum = 2000000001;
	int start = 0, end = N - 1;

	int res1, res2;
	while (start < end) {
		if (abs(num[start] + num[end]) < sum) {
			sum = abs(num[start] + num[end]);
			res1 = num[start];
			res2 = num[end];
		}
		if (num[start] + num[end] < 0) {
			start++;
		}
		else {
			end--;
		}
	}
	cout << res1 << " " << res2;
}