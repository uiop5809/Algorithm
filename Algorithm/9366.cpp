#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, a, b, c, num;
	string str = "";
	cin >> T;
	for(int i = 1; i <= T; i++){
		bool flag = true;
		cin >> a >> b >> c;
		num = max({ a, b, c });
		if (num == a) {
			if (a >= b + c) flag = false;
		}
		else if (num == b) {
			if (b >= a + c) flag = false;
		}
		else if (num == c) {
			if (c >= a + b) flag = false;
		}
		if (a == b && b == c) {
			str = "equilateral";
		}
		else if (a == b && b != c || a != b && b == c) {
			str = "isosceles";
		}
		else if (a != b && b != c) {
			str = "scalene";
		}
		cout << "Case #" << i << ": ";
		if (flag) cout << str << "\n";
		else cout << "invalid!" << "\n";
	}
}