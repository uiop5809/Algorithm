#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, s, n, p, q;
	cin >> T;
	while (T--) {
		int res = 0;
		cin >> s >> n;
		res += s;
		while (n--) {
			cin >> p >> q;
			res += p * q;
		}
		cout << res << "\n";
	}
}