#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, res = 0;
	cin >> n;
	int money = 1000 - n;
	res += money / 500;
	money %= 500;
	res += money / 100;
	money %= 100;
	res += money / 50;
	money %= 50;
	res += money / 10;
	money %= 10;
	res += money / 5;
	money %= 5;
	res += money / 1;

	cout << res;
}