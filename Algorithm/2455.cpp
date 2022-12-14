#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, y, num = 0, res = 0;
	for (int i = 0; i < 4; i++) {
		cin >> x >> y;
		num += -x + y;
		res = max(res, num);
	}
	cout << res;
}