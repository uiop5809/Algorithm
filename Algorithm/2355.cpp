#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long A, B;
	cin >> A >> B;
	if (A > B) {
		int temp = A;
		A = B;
		B = temp;
	}
	cout << (B * (B + 1)) / 2 - (A * (A - 1)) / 2;
	return 0;
}