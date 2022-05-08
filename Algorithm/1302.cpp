#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int N;
string book;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	map <string, int> m;

	while(N--){
		cin >> book;
		m[book]++;
	}
	int res = 0;
	for (auto i:m) {
		res = max(res, i.second);
	}
	for (auto i:m) {
		if (res == i.second) {
			cout << i.first;
			return 0;
		}
	}
}