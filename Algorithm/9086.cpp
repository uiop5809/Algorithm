#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	string str;

	cin >> T;
	while (T--) {
		cin >> str;
		cout << str[0] << str[str.size() - 1] << "\n";
	}
}