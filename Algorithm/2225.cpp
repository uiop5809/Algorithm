#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

#define MOD 1000000000;

//dp[a][b] = c
//a�� ���ؼ� ���� b�� �Ǵ� ����� �� c

int N, K;
long long dp[201][201];

long long dynamic(int n, int k) {
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= k; i++) { //k�� ���ؼ�
		for (int j = 0; j <= n; j++) { //n �����
			for (int k = 0; k <= j; k++) { //����� ��
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
		}
	}
	return dp[k][n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;
	cout << dynamic(N, K);
}