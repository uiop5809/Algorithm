#include <iostream>
#include <algorithm>
using namespace std;

int n, num[100001], x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> x;
	sort(num, num + n);

	int sum = 0;
	int start = 0, end = n - 1;

	int cnt = 0;
	while (start < end) {
		if (num[start] + num[end] == x) {
			cnt++;
		}
		if (num[start] + num[end] >= x) {
			end--;
		}
		else if (num[start] + num[end] < x) {
			start++;
		}
	}
	cout << cnt;
}