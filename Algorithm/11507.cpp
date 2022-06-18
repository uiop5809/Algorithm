#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	map<pair<string, string>, int> m;

	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i += 3) {
		string kind = str.substr(i, 1);
		string num = str.substr(i + 1, 2);
		m[{kind, num}]++;
	}

	int Pcnt = 13, Kcnt = 13, Hcnt = 13, Tcnt = 13;
	for (auto i : m) {
		if (i.second >= 2) {
			cout << "GRESKA";
			return 0;
		}
		if (i.first.first == "P") Pcnt--;
		else if (i.first.first == "K") Kcnt--;
		else if (i.first.first == "H") Hcnt--;
		else if (i.first.first == "T") Tcnt--;
	}
	cout << Pcnt << " " << Kcnt << " " << Hcnt << " " << Tcnt;
}