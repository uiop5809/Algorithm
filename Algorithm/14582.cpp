#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	bool flag = false;
	int num1[9], num2[9], sum1 = 0, sum2 = 0;
	for (int i = 0; i < 9; i++) cin >> num1[i];
	for (int i = 0; i < 9; i++) cin >> num2[i];
	for (int i = 0; i < 9; i++) {
		sum1 += num1[i];
		if (sum1 > sum2) flag = true;
		sum2 += num2[i];
		if (sum1 > sum2) flag = true;
	}
	if (flag) cout << "Yes";
	else cout << "No";
}