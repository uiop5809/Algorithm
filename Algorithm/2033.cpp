#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, cnt = 0;
	cin >> N;
	while (N / 10 > 0) {
		if (N % 10 >= 5) N += 10;
		N /= 10;
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		N *= 10;
	}
	cout << N;
}