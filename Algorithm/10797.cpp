#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, num, cnt = 0;
	cin >> n;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		if (num == n) cnt++;
	}
	cout << cnt;
}