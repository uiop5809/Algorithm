#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, m;

long long func(int n, int x) { // nÀ» x·Î ³ª´²ÁÜ
	int num = 0;
	for (long long i = x; n / i >= 1; i *= x) {
		num += n / i;
	}
	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	long long five = 0;
	long long two = 0;

	five = func(n, 5) - func(n - m, 5) - func(m, 5);
	two = func(n, 2) - func(n - m, 2) - func(m, 2);
	cout << min(five, two);
}