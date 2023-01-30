#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int A, B, C, D;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> C >> D;
	B += D / 60;
	C += D % 60;

	int Ccnt = 0;
	while (C >= 60) {
		C -= 60;
		Ccnt++;
	}
	B += Ccnt;

	int Bcnt = 0;
	while (B >= 60) {
		B -= 60;
		Bcnt++;
	}

	A += Bcnt;
	while (A >= 24) {
		A -= 24;
	}
	cout << A << " " << B  << " " << C;
}