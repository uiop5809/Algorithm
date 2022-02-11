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

typedef long long ll;

ll N, C;
ll house[200001];

int binary_search(int left, int right, int C) {
	//모든 거리가 같아야 한다.
	int distance;

	while (left <= right) {
		int mid = (left + right) / 2;
		int C_cnt = 1;
		int index = 0;
		for (int i = 1; i < N; i++) {
			if (mid <= house[i] - house[index]) {
				index = i;
				C_cnt++;
			}
		}
		if (C_cnt >= C) {
			//공유기 수를 줄여야 함 = 설치 간격을 넓혀야 함
			distance = max(mid, distance);
			left = mid + 1;
		}
		else {
			//공유기 수를 늘려야 함 = 설치 간격을 줄여야 함
			right = mid - 1;
		}
	}
	return distance;
}


int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> house[i];
	}
	sort(house, house + N);
	cout << binary_search(1, house[N - 1] - 1, C);
}