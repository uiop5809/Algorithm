#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, res = 0;
	cin >> N;
	while (N >= 0) {
		if (N % 5 == 0) {
			res += N / 5;
			cout << res;
			return 0;
		}
		N -= 3;
		res++;
	}
	cout << -1;
}