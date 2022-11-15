#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, alpha[26];
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		for (int i = 0; i < 26; i++) {
			alpha[i] = 65 + i;
		}
		for (int i = 0; i < str.size(); i++) {
			alpha[str[i] - 65] = 0;
		}
		int sum = 0;
		for (int i = 0; i < 26; i++) {
			sum += alpha[i];
		}
		cout << sum << "\n";
	}
}