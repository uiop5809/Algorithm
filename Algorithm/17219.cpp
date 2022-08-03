#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int N, M;
string adress, passwd, res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	map <string, string> m;

	cin >> N >> M;
	while (N--) {
		cin >> adress >> passwd;
		m[adress] = passwd;
	}
	while (M--) {
		cin >> res;
		cout << m.find(res)->second << "\n";
	}
}