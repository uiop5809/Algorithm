#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int T;
string str1, str2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		int cnt1[26] = { 0 }, cnt2[26] = { 0 };
		cin >> str1 >> str2;
		if (str1.size() != str2.size()) {
			cout << str1 << " & " << str2 << " are NOT anagrams.\n";
		}
		else {
			for (int i = 0; i < str1.size(); i++) {
				cnt1[str1[i] - 'a']++;
			}
			for (int i = 0; i < str2.size(); i++) {
				cnt2[str2[i] - 'a']++;
			}
			int cnt = 0;
			for (int i = 0; i < 26; i++) {
				if (cnt1[i] != cnt2[i]) cnt++;
			}
			if(cnt > 0) cout << str1 << " & " << str2 << " are NOT anagrams.\n";
			else cout << str1 << " & " << str2 << " are anagrams.\n";
		}
	}
}