#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

int N, M, K, x, y, option, a;
int indegree[100001], construct[100001];
bool check;

vector <int> v[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		indegree[y]++;
	}
	for (int i = 0; i < K; i++) {
		cin >> option >> a;
		if (option == 1) { // °Ç¼³
			if (indegree[a] == 0) {
				construct[a]++;
				if (construct[a] == 1) {
					for (int j = 0; j < v[a].size(); j++) {
						int next = v[a][j];
						indegree[next]--;
					}
				}
			}
			else check = true;
		}
		else if (option == 2) { // ÆÄ±«
			if (construct[a] > 0) {
				construct[a]--;
				if (construct[a] == 0) {
					for (int j = 0; j < v[a].size(); j++) {
						int next = v[a][j];
						indegree[next]++;
					}
				}
			}
			else check = true;
		}
	}
	if (check) cout << "Lier!";
	else cout << "King-God-Emperor";
}