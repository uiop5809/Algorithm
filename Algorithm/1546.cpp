#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int N, score[1001];
double sum = 0;

int main() {
	cin >> N;
	int max = 0;
	for (int i = 0; i < N; i++) {
		cin >> score[i];
		if (max < score[i]) max = score[i];
		sum += score[i];
	}
	sum = (sum / max * 100) / N;

	cout << fixed;
	cout.precision(6);
	cout << sum;
}