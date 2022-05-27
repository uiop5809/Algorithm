#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, x, y;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> x >> y;
		cout << "Case " << i << ": " << x + y << "\n";
	}
}