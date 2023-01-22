#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector <int> v;
	for (int i = 0; i < 50; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int h, res;
	cin >> h;
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < 50; i++) {
		if (v[i] == h) {
			res = i + 1;
		}
	}
	if (1 <= res && res <= 5) cout << "A+";
	else if (5 < res && res <= 15) cout << "A0";
	else if (15 < res && res <= 30) cout << "B+";
	else if (30 < res && res <= 35) cout << "B0";
	else if (35 < res && res <= 45) cout << "C+";
	else if (45 < res && res <= 48) cout << "C0";
	else cout << "F";
}