#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, p, C;
string name;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> p;
		int max = 0;
		string res;
		for (int i = 0; i < p; i++) {
			cin >> C >> name;
			if (max < C) {
				max = C;
				res = name;
			}
		}
		cout << res << "\n";
	}
}