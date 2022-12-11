#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A[10], B[10], sumA = 0, sumB = 0;
	for (int i = 0; i < 10; i++) cin >> A[i];
	for (int i = 0; i < 10; i++) cin >> B[i];
	for (int i = 0; i < 10; i++) {
		if (A[i] > B[i]) sumA += 3;
		else if (A[i] < B[i]) sumB += 3;
		else {
			sumA += 1;
			sumB += 1;
		}
	}
	cout << sumA << " " << sumB <<"\n";
	bool flag = false;
	if (sumA == sumB) {
		for (int i = 9; i >= 0; i--) {
			if (A[i] != B[i]) {
				if (A[i] > B[i]) cout << 'A';
				else cout << 'B';
				flag = true; // 다른 게 있다
			}
			if (flag) break;
		}
		if (!flag) cout << 'D';
	}
	else {
		if (sumA > sumB) cout << 'A';
		else cout << 'B';
	}
}