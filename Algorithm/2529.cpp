#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(vector<int> &v, vector<char> &op) {
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '<' && v[i] > v[i + 1]) return false;
		if (op[i] == '>' && v[i] < v[i + 1]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
	int k;
	cin >> k;
	vector<char> op(k);
	for (int i = 0; i < k; i++) {
		cin >> op[i];
	}
	vector<int> v1(k + 1);
	vector<int> v2(k + 1);
	for (int i = 0; i < k + 1; i++) {
		v1[i] = i;
		v2[i] = 9 - i;
	}

	do {
		if (check(v1, op)) break;
	} while (next_permutation(v1.begin(), v1.end()));

	do {
		if (check(v2, op)) break;
	} while (prev_permutation(v2.begin(), v2.end()));

	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i];
	}
	cout << "\n";
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i];
	}	
}