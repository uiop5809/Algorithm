#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	map <string, int> m;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		int idx;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '.') idx = j + 1;
		}
		string s = str.substr(idx);
		if (m.count(s) == 0) m[s] = 1;
		else m[s]++;
	}
	for (auto i : m) {
		cout << i.first << " " << i.second << "\n";
	}
}