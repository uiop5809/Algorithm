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
		//��緹�̴� �ּ� 1��, �������� �κ���
		int mid = (left + right) / 2;
		for (int i = 0; i < N; i++) {
			if (g_time[i] + g_time_sum > mid) {
				bluelay++;
				g_time_sum = 0;
				//���ο� ��緹�̰� �������ϱ� �� ��緹�̿� ����� ���� �ʱ�ȭ
			}
			g_time_sum += g_time[i];
		}
		//�ּ� ��緹�� ���� ã��
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
	//�ִ� ���� �ð�, ���� �ð� ����
	cout << binary_search(g_max, g_total);
}