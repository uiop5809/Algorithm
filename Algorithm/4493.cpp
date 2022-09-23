#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, sum1 = 0, sum2 = 0;
		char c1, c2;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> c1 >> c2;
			if (c1 == 'R' && c2 == 'R' || c1 == 'P' && c2 == 'P' || c1 == 'S' && c2 == 'S') continue;
			else if (c1 == 'R' && c2 == 'P' || c1 == 'P' && c2 == 'S' || c1 == 'S' && c2 == 'R') sum2++;
			else if (c1 == 'P' && c2 == 'R' || c1 == 'S' && c2 == 'P' || c1 == 'R' && c2 == 'S') sum1++;
		}
		if (sum1 > sum2) cout << "Player 1\n";
		else if (sum1 < sum2) cout << "Player 2\n";
		else cout << "TIE\n";
	}
}