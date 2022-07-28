#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int num1[10001], num2[10001], sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() < s2.size()) swap(s1, s2);

	for (int i = 0; i < s1.size(); i++) {
		num1[i] = s1[s1.size() - 1 - i] - '0';
	}
	for (int i = 0; i < s2.size(); i++) {
		num2[i] = s2[s2.size() - 1 - i] - '0';
	}

	vector<int> res;
	for (int i = 0; i < s1.size(); i++) {
		sum = num1[i] + num2[i];
		if (sum >= 10) {
			num1[i + 1]++;
			sum -= 10;
		}
		res.push_back(sum);
	}

	bool flag = true;
	if (num1[s1.size()] != 0) cout << 1;
	else {
		if (res[res.size() - 1] == 0) flag = false;
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		if (res[i] != 0) flag = true;
		if(flag) cout << res[i];
	}
}