#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	long long res = 5;
	cin >> n;

	if (n == 1) cout << res;
	else {
		for (int i = 2; i <= n; i++) {
			res += 3 * i + 1;
		}
		cout << res % 45678;
	}
}