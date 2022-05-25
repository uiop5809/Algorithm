#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string str, rstr;
	cin >> str;
	rstr = str;
	reverse(str.begin(), str.end());
	if (rstr == str) cout << "1";
	else cout << "0";
}