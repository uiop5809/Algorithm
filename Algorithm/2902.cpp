#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;
	cout << str[0];
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-') cout << str[i + 1];
	}
}