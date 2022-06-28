#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

string str;

bool palindrome(int idx) {
	int half = (str.size() - idx) / 2;
	for (int i = 0; i < half; i++) {
		if (str[i + idx] != str[str.size() - 1 - i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;
	int size = str.size();
	for (int i = 0; i < size; i++) {
		if (palindrome(i)) {
			cout << size + i;
			break;
		}
	}
}