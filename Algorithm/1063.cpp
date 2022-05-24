#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, arr[9][9];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str, king, stone;
	cin >> king >> stone >> N;
	
	int ki = king[1] - '0' - 1;
	int kj = 7 - (king[0] - 'A');
	int si = stone[1] - '0' - 1;
	int sj = 7 - (stone[0] - 'A');

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "R") {
			if (kj + 1 > 7 || sj + 1 > 7) continue;
			kj += 1;
			sj += 1;
		}
		else if (str == "L") {
			if (kj - 1 < 0 || sj - 1 < 0) continue;
			kj -= 1;
			sj -= 1;
		}
		else if (str == "B") {
			if (ki + 1 > 7 || si + 1 > 7) continue;
			ki += 1;
			si += 1;
		}
		else if (str == "T") {
			if (ki - 1 < 0 || si - 1 < 0) continue;
			ki -= 1;
			si -= 1;
		}

		else if (str == "RT") {
			if (kj + 1 > 7 || sj + 1 > 7 || ki - 1 < 0 || si - 1 < 0) continue;
			kj += 1;
			sj += 1;
			ki -= 1;
			si -= 1;
		}
		else if (str == "LT") {
			if (kj - 1 < 0 || sj - 1 < 0 || ki - 1 < 0 || si - 1 < 0) continue;
			kj -= 1;
			sj -= 1;
			ki -= 1;
			si -= 1;
		}
		else if (str == "RB") {
			if (kj + 1 > 7 || sj + 1 > 7 || ki + 1 > 7 || si + 1 > 7) continue;
			kj += 1;
			sj += 1;
			ki += 1;
			si += 1;
		}
		else if (str == "LB") {
			if (kj - 1 < 0 || sj - 1 < 0 || ki + 1 > 7 || si + 1 > 7) continue;
			kj -= 1;
			sj -= 1;
			ki += 1;
			si += 1;
		}
	}
	cout << kj << " " << ki + 1<< "\n";
	cout << sj << " " << si + 1;
}