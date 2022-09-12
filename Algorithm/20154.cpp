#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int num[26] = { 3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		sum += num[str[i] - 'A'];
	}
	if (sum % 2 == 0) cout << "You're the winner?";
	else cout << "I'm a winner!";
}