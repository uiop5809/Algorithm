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

ll K, N, lan_max = 0;
ll lan_len[10001];

ll binary_search(ll left, ll right) {
	//������ �� (���� �� �ִ� ������ ��)
	while (left <= right) {
		ll mid = (left + right) / 2;
		int cutting = 0; //�ڸ���
		for (int i = 0; i < K; i++) {
			cutting += lan_len[i] / mid;
		}
		if (N <= cutting) { //���� �� �ִ� ���� ���� N���� ���� ������ �ڸ��� �ø�
			lan_max = max(lan_max, mid); //���� �� �������� ������Ʈ
			left = mid + 1;
		}
		else { //���� �� �ִ� �������� N���� ���� ������ ������ ����
			right = mid - 1;
		}
	}
	return lan_max; //������ ������ �� ���� �� ����
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> K >> N;
	ll lan = 0;
	for (int i = 0; i < K; i++) {
		cin >> lan_len[i];
		lan = max(lan, lan_len[i]); // �ִ� ���� ����
	}
	cout << binary_search(1, lan);
	//left = 1, right = �ִ� ���� ����
}