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
	//최적의 해 (만들 수 있는 랜선의 수)
	while (left <= right) {
		ll mid = (left + right) / 2;
		int cutting = 0; //자르기
		for (int i = 0; i < K; i++) {
			cutting += lan_len[i] / mid;
		}
		if (N <= cutting) { //만들 수 있는 랜선 수가 N보다 많기 때문에 자르기 늘림
			lan_max = max(lan_max, mid); //가장 긴 랜선길이 업데이트
			left = mid + 1;
		}
		else { //만들 수 있는 랜선수가 N보다 적기 때문에 랜선수 줄임
			right = mid - 1;
		}
	}
	return lan_max; //가능한 랜선들 중 가장 긴 랜선
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> K >> N;
	ll lan = 0;
	for (int i = 0; i < K; i++) {
		cin >> lan_len[i];
		lan = max(lan, lan_len[i]); // 최대 랜선 길이
	}
	cout << binary_search(1, lan);
	//left = 1, right = 최대 랜선 길이
}