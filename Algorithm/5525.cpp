#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	string str;

	cin >> N >> M >> str;
	
	int res = 0;
	for (int i = 0; i < M; i++) {
		if (str[i] == 'O') continue;
		
		int cnt = 0;
		while (str[i + 1] == 'O' && str[i + 2] == 'I') {
			cnt++;
			i += 2;
			if (cnt == N) {
				cnt--;
				res++;
			}
		}
	}
	cout << res;
}