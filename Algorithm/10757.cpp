#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string A, B;
	cin >> A >> B;
	if (A.size() < B.size()) swap(A, B);
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	if (A.size() == B.size()) {
		for (int i = 0; i < B.size(); i++) {
			int sum = (A[i] - '0') + (B[i] - '0');
			if (sum >= 10) {
				sum -= 10;
				A[i] = sum + '0';
				A[i + 1] += 1;
				if (i == B.size() - 1) A += '1';
			}
			else A[i] += B[i] - '0';
		}
	}
	else {
		for (int i = 0; i < B.size(); i++) {
			int sum = (A[i] - '0') + (B[i] - '0');
			if (sum >= 10) {
				sum -= 10;
				A[i] = sum + '0';
				A[i + 1] += 1;
			}
			else A[i] += B[i] - '0';
		}
	}

	reverse(A.begin(), A.end());
	cout << A;
}