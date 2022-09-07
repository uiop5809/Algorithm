#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n == 1) cout << "#";
		else {
			for (int i = 0; i < n; i++) cout << "#";
			cout << "\n";
			for (int i = 0; i < n - 2; i++) {
				cout << "#";
				for (int j = 0; j < n - 2; j++) {
					cout << "J";
				}
				cout << "#\n";
			}
			for (int i = 0; i < n; i++) cout << "#";
		}
		cout << "\n\n";
	}
}