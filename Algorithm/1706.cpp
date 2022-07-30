#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int R, C;
string str[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> str[i];
	}
	vector<string> v;
	for (int i = 0; i < R; i++) {
		string temp = "";
		for (int j = 0; j < C; j++) {
			if (str[i][j] == '#') {
				v.push_back(temp);
				temp = "";
			}
			else temp += str[i][j];
		}
		if (temp != "") v.push_back(temp);
	}
	for (int i = 0; i < C; i++) {
		string temp = "";
		for (int j = 0; j < R; j++) {
			if (str[j][i] == '#') {
				v.push_back(temp);
				temp = "";
			}
			else temp += str[j][i];
		}
		if (temp != "") v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (v[i].size() >= 2) {
			cout << v[i];
			break;
		}
	}
}