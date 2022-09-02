#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	cin.ignore();
	while(T--) {
		string str;
		getline(cin, str);
		string res = "";
		vector<string> v;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				v.push_back(res);
				res = "";
			}
			else res += str[i];
		}
		if (res != "") 	v.push_back(res);

		vector<string> v1;
		while (1) {
			getline(cin, str);
			if (str == "what does the fox say?") break;

			int idx;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == 'g' && str[i + 1] == 'o' && str[i + 2] == 'e' && str[i + 3] == 's') {
					idx = i + 5;
				}
			}
			string sound = str.substr(idx);
			v1.push_back(sound);
		}
		for (int i = 0; i < v.size(); i++) {
			bool flag = false;
			for (int j = 0; j < v1.size(); j++) {
				if (v[i] == v1[j]) flag = true;
			}
			if (!flag) cout << v[i] << " ";
		}
	}
}