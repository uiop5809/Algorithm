#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;

	if (str1.size() < str2.size()) swap(str1, str2);
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	for (int i = 0; i < str2.size(); i++) {
		str1[i] += str2[i] - '0';
		if (str1[i] > '1') {
			str1[i + 1]++;
			str1[i] -= 2;
		}
	}
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] > '1') {
			str1[i + 1]++;
			str1[i] -= 2;
		}
	}
	// 마지막 올림수
	if (str1[str1.size()]) str1 += str1[str1.size()] + '0';

	reverse(str1.begin(), str1.end());
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] != '0') {
			int idx = 0;
			for (int j = 0; j < str1.size(); j++) {
				if (str1[j] == '1') {
					idx = j;
					break;
				}
			}
			if (idx > 0) cout << str1.substr(idx) << " ";
			else cout << str1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}