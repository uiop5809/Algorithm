#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector <int> v(21);

	for (int i = 0; i < 21; i++) {
		v[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		int x, y;
		cin >> x >> y;
		reverse(v.begin() + x, v.begin() + y + 1);
	}
	for (int i = 1; i <= 20; i++) {
		cout << v[i] << " ";
	}
}