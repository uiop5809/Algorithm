#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		string str;
		getline(cin, str);
		if (str == "*") break;

		string temp = "";
		vector<string> v;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				v.push_back(temp);
				temp = "";
			}
			else {
				temp += toupper(str[i]);
			}
		}
		if (temp != "") v.push_back(temp);

		bool flag = true;
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i][0] != v[i + 1][0]) flag = false;
		}
		if (flag) cout << "Y\n";
		else cout << "N\n";
	}
}