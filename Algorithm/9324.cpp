#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;

		bool flag = true;
		int alphabet[26] = { 0 };
		for (int i = 0; i <	s.size(); i++) {
			alphabet[s[i] - 'A']++;
			if (alphabet[s[i] - 'A'] == 3) {
				if (i == s.size() - 1) {
					flag = false;
					break;
				}
				else if (s[i + 1] != s[i]){
					flag = false;
					break;
				}
				i++;
				alphabet[s[i] - 'A'] = 0;
			}
		}
		if (flag) cout << "OK\n";
		else cout << "FAKE\n";
	}
	return 0;
}