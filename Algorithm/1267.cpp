#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N, num;
int sumY, sumM;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;

		int c = num;
		sumY += c / 30 * 10;
		if (c % 30 >= 0) sumY += 10;

		sumM += num / 60 * 15;
		if (num % 60 >= 0) sumM += 15;
	}
	if (sumY < sumM) cout << "Y " << sumY;
	else if (sumY > sumM) cout << "M " << sumM;
	else cout << "Y M " << sumY;
}