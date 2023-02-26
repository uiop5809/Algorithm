#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, x1, y1, r1, x2, y2, r2;

	cin >> T;
	while (T--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int dist = pow((x1 - x2), 2) + pow((y1 - y2), 2);
		int num1 = pow((r1 - r2), 2);
		int num2 = pow((r1 + r2), 2);

		if (dist == 0) {
			if (num1 == 0) cout << -1 << "\n";
			else cout << 0 << "\n";
		}
		else if (dist == num1 || dist == num2) cout << 1 << "\n";
		else if (num1 < dist && dist < num2) cout << 2 << "\n";
		else cout << 0 << "\n";
	}
}