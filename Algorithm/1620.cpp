#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int N, M;
string str, quest;
string mp2[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	map <string, int> mp1;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		mp1.insert({ str, i });
		mp2[i] = str;
	}
	for (int i = 0; i < M; i++) {
		cin >> quest;
		if (isdigit(quest[0])) cout << mp2[stoi(quest)];
		else cout << mp1[quest];
		cout << "\n";
	}
}