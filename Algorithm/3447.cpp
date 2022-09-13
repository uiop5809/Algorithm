#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	while (getline(cin, str)) {
		while (str.find("BUG") != -1) {
			int idx = str.find("BUG");
			str.erase(idx, 3);
		}
		cout << str << "\n";
	}
}