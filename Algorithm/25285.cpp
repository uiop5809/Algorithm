#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		double cm, kg;
		int score = 0;
		cin >> cm >> kg;
		double bmi = kg / (cm * cm * 0.0001);
		if (cm < 140.1) score = 6;
		else if (cm < 146) score = 5;
		else if (cm < 159) score = 4;
		else if (cm < 161) {
			if (bmi < 16 || bmi >= 35) score = 4;
			else if (16 < bmi && bmi < 35) score = 3;
		}
		else if (cm < 204) {
			if (bmi < 16 || bmi >= 35) score = 4;
			else if (16 <= bmi && bmi < 18.5 || 30 <= bmi && bmi < 35) score = 3;
			else if (18.5 <= bmi && bmi < 20 || 25 <= bmi && bmi < 30) score = 2;
			else if (20 <= bmi && bmi < 25) score = 1;
		}
		else score = 4;
		cout << score << "\n";
	}
	
}