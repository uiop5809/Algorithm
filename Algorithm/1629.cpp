#include <iostream>
using namespace std;

int A, B, C;

long long calc(long long a, long long b) {
	if (b == 0) return 1;
	else if (b == 1) return a;

	if (b % 2 > 0) return calc(a, b - 1) * a;
	long long mid = calc(a, b / 2);
	mid %= C;
	return mid * mid % C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> C;
	cout << calc(A, B) % C;
}
