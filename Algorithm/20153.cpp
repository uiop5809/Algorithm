#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num, num1, res = 0;
		cin >> num;
		num1 = num;
		while (num > 0) {
			if (num % 2 == 1) res++;
			num /= 2;
		}
		if (res % 2 == 1) sum += num1;
	}
	cout << sum << sum;
}