#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		string str, str1 = "1", str2 = "2";
		cin >> str;
		if (str == "0") break;
		int size = str.size();

		int num = 0, res = 0;
		while (1) {
			str1 = str;
			reverse(str.begin(), str.end());
			str2 = str;

			if (str1 == str2) break;
			num = stoi(str1);
			num++;
			str = to_string(num);
			for (int i = 0; i < size - str.size(); i++) {
				str = '0' + str;
			}
			if(str.size() != size) str = '0' + str;
			res++;
		}
		cout << res << "\n";
	}
}