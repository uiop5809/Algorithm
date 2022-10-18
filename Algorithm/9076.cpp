#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int num;
		vector <int> v;
		for (int i = 0; i < 5; i++) {
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		if (v[3] - v[1] >= 4) {
			cout << "KIN\n";
		}
		else {
			int sum = 0;
			for (int i = 1; i <= 3; i++) {
				sum += v[i];
			}
			cout << sum << "\n";
		}
	}
}