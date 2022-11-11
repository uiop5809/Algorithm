#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	int num[26] = { 0 };
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		num[str[i] - 'A']++;
	}
	if (num[0]) {
		for (int i = 0; i < str.size(); i++) {
			if ('B' <= str[i] && str[i] <= 'D' || str[i] == 'F') str[i] = 'A';
		}
	}
	else if (num[1]) {
		for (int i = 0; i < str.size(); i++) {
			if ('C' <= str[i] && str[i] <= 'D' || str[i] == 'F') str[i] = 'B';
		}
	}
	else if (num[2]) {
		for (int i = 0; i < str.size(); i++) {
			if ('D' <= str[i] && str[i] <= 'D' || str[i] == 'F') str[i] = 'C';
		}
	}
	else {
		for (int i = 0; i < str.size(); i++) {
			str[i] = 'A';
		}
	}
	for (int i = 0; i < str.size(); i++) {
		cout << str[i];
	}
}