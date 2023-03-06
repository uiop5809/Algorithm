#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n[46];
	int num;

	n[0] = 0;
	n[1] = 1;

	cin >> num;
	for (int i = 2; i <= num; i++) {
		n[i] = n[i - 1] + n[i - 2];
	}
	cout << n[num];
}