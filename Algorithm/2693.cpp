#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int compare(int a, int b) {
	return a > b;
}
int main() {
	int T;
	int num[10];

	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> num[j];
		}
		sort(num, num + 10, compare);
		cout << num[2] << "\n";
	}
}