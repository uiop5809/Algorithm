#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	bool c = false, java = false, err = false;
	string res;
	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			if (!i || c) { 
				err = true;
				break;
			}
			res += '_';
			res += s[i] - 'A' + 'a';
			java = true;
		}
		else if (s[i] == '_') {
			if (!i || java || i == s.size() - 1 || s[i + 1] == '_' || ('A' <= s[i + 1] && s[i + 1] <= 'Z')) {
				err	= true;
				break;
			}
			res += s[i + 1] - 'a' + 'A';
			i++;
			c = true;
		}
		else res += s[i];
	}
	if (err) cout << "Error!\n";
	else cout << res << "\n";
	return 0;
}