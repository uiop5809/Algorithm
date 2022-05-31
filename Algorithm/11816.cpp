#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;
	int num, res = 0, idx = 1;
	
	if (str[0] == '0' && str[1] == 'x') { // 16진수
		for (int i = str.size() - 1; i > 1; i--) {
			if ('a' <= str[i] && str[i] <= 'z') {
				num = str[i] - 'a';
				num += 10;
				num *= idx;
			}
			else {
				num = str[i] - '0';
				num *= idx;
			}
			res += num;
			idx *= 16;
		}
		cout << res;
	}
	else if (str[0] == '0') { // 8진수
		for (int i = str.size() - 1; i > 0; i--) {
			num = str[i] - '0';
			num *= idx;
			res += num;
			idx *= 8;
		}
		cout << res;
	}
	else { // 10진수
		cout << str;
	}
}