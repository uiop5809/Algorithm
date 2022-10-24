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
		int num, sum = 0;
		vector <int> v;
		for (int i = 0; i < 7; i++) {
			cin >> num;
			if (num % 2 == 0) {
				sum += num;
				v.push_back(num);
			}
		}
		sort(v.begin(), v.end());
		cout << sum << " " << v[0] << "\n";
	}
}