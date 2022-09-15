#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num[9][9], res = 0, resi = 1, resj = 1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> num[i][j];
			if (res < num[i][j]) {
				res = num[i][j];
				resi = i + 1;
				resj = j + 1;
			}
		}
	}
	cout << res << "\n" << resi << " " << resj;
}