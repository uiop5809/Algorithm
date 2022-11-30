#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, sum = 0;
	vector <int> v;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		v.push_back(n);
		sum += n;
	}
	sort(v.begin(), v.end());
	cout << sum / 5 << "\n" << v[2];
}