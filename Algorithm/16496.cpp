#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<string> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end(), cmp);

	string str = "";
	for (int i = 0; i < N; i++) {
		str += num[i];
	}
	if (str[0] == '0') {
		cout << 0;
		return 0;
	}
	cout << str;
}