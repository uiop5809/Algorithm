#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	for (int i = 1; i <= 999; i++) {
		string res = "";
		int A = i, B = 0;
		for (int j = i; j <= 999; j++) {
			res += to_string(j);
			if (str.size() <= res.size()) {
				B = j;
				break;
			}
		}
		if (res == str) {
			cout << A << " " << B;
			break;
		}
	}
}