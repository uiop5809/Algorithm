#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string N;
	while (1) {
		cin >> N;
		if (N == "0") break;
		while (N.size() != 1) {
			int sum = 0;
			for (int i = 0; i < N.size(); i++) {
				sum += N[i] - '0';
			}
			N = to_string(sum);
		}
		cout << N << "\n";
	}
}