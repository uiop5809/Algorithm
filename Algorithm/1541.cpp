#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> num; // 숫자
	vector<char> v; // 부호

	string str;
	cin >> str;

	string s = "";
	for (int i = 0; i < str.size(); i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			s += str[i];
		}
		else if (str[i] == '-' || str[i] == '+') {
			v.push_back(str[i]);
			num.push_back(stoi(s));
			s = "";
		}
	}
	num.push_back(stoi(s));

	if (v.size() > 0) {
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] == '-' && v[i + 1] == '+') {
				while (v[i + 1] == '+') {
					v[i + 1] = '-';
				}
			}
		}
	}

	int res = num[0];
	for (int i = 0; i < num.size() - 1; i++) {
		if (v[i] == '-') {
			res -= num[i + 1];
		}
		else if (v[i] == '+') {
			res += num[i + 1];
		}
	}
	cout << res;
}