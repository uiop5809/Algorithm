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

ll N, M, g_total = 0, g_max = 0;
ll g_time[100001];

ll binary_search(ll left, ll right) {
	while (left <= right) {
		int bluelay = 1, g_time_sum = 0; 
		//블루레이는 최소 1개, 레슨들의 부분합
		int mid = (left + right) / 2;
		for (int i = 0; i < N; i++) {
			if (g_time[i] + g_time_sum > mid) {
				bluelay++;
				g_time_sum = 0;
				//새로운 블루레이가 생겼으니까 전 블루레이에 저장된 레슨 초기화
			}
			g_time_sum += g_time[i];
		}
		//최소 블루레이 개수 찾기
		if (bluelay <= M) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> g_time[i];
		g_total += g_time[i];
		if (g_time[i] > g_max) {
			g_max = g_time[i];
		}
	}
	//최대 레슨 시간, 레슨 시간 총합
	cout << binary_search(g_max, g_total);
}