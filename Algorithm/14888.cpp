#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int cal(int a, int b, char c) {
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else if (c == '*') return a * b;
	else if (c == '/') return a / b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<int> num;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		num.push_back(n);
	}
	vector<char> op;
	for (int i = 0; i < 4; i++) { // +, -, *, /
		int option;
		cin >> option;
		if (i == 0) while (option--) op.push_back('+');
		if (i == 1) while (option--) op.push_back('-');
		if (i == 2) while (option--) op.push_back('*');
		if (i == 3) while (option--) op.push_back('/');
	}

	sort(op.begin(), op.end());
	int MIN = 1e9, MAX = -1e9;
	do {
		vector<int> tmp_num = num;
		int res = 0;
		for (int i = 0; i < op.size(); i++) {
			tmp_num[i + 1] = cal(tmp_num[i], tmp_num[i + 1], op[i]);
		}
		res = tmp_num[N - 1];
		MIN = min(MIN, res);
		MAX = max(MAX, res);
	} while (next_permutation(op.begin(), op.end()));

	cout << MAX << "\n" << MIN;
}