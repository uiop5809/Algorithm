#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	double A, B;
	cin >> A >> B;

	cout << fixed;
	cout.precision(5);
	cout << (double)1 / (1 + pow(10, (B - A) / 400));
}
