#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	set<string> set;
	string res = "";
	for (int i = 0; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			res += s[j];
			set.insert(res);
		}
		res = "";
	}
	cout << set.size();
}