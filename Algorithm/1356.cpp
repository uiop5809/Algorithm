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

	string num;
	cin >> num;

	int first = 1, second = 1;
	bool flag = false;

	for (int i = 0; i < num.size()-1; i++) {
		for (int j = 0; j < i + 1; j++) {
			first *= (num[j] - '0');
		}
		for (int j = i + 1; j < num.size(); j++) {
			second *= (num[j] - '0');
		}
		if (first == second) flag = true;
		first = 1, second = 1;
	}
	if (flag) cout << "YES";
	else cout << "NO";
}