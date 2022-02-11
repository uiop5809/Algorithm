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

int N, M, num;
int A[100001];

int binary_search(int left, int right, int find) {
	while (left <= right) {
		int mid;
		mid = (left + right) / 2;
		
		if (find == A[mid]) {
			return 1;
		}
		else if (find > A[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return 0;
	//값을 찾지 못함 = 수가 존재하지 않음, 0 반환
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		cout << binary_search(0, N-1, num) << "\n";
		//left = 0, right = N-1 (index값)
	}
}