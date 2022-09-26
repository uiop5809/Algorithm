#include <iostream>
using namespace std;

int main() {
	int e, f, c, res = 0;
	cin >> e >> f >> c;
	int sum = e + f;
	while (sum >= c) {
		res += sum / c;
		sum = sum / c + sum % c;
	}
	cout << res;
}