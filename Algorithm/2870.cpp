#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<string> v;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		string res = "";
		for (int j = 0; j < str.size(); j++) {
			if ('a' <= str[j] && str[j] <= 'z') {
				if (res != "") {
					v.push_back(res);
					res = "";
				}
			}
			else res += str[j];
		}
		if (res != "") v.push_back(res);
	}
	vector <string> v1;
	for (int i = 0; i < v.size(); i++) {
		int idx = v[i].size() - 1;
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] != '0') {
				idx = j;
				break;
			}
		}
		string str = v[i].substr(idx);
		if (idx == v[i].size() - 1 && v[i][v[i].size() - 1] == '0') str = "0";
		v1.push_back(str);
	}

	sort(v1.begin(), v1.end(), cmp);
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << "\n";
	}
}