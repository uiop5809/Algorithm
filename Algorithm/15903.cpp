#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
long long num[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	while (m--) {
		sort(num, num + n);
		long long sum = num[0] + num[1];
		num[0] = sum;
		num[1] = sum;
	}
	long long res = 0;
	for (int i = 0; i < n; i++)  res += num[i];
	cout << res;
}