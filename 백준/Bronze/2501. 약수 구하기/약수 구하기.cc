#include <iostream>
#include <vector>

using namespace std;

int find_num(const int num1, const int num2) {
	vector<int> factors(num1 + 1);

	for (int i = 1; i <= num1; ++i) {
		if (num1 % i == 0)
			factors[i] = i;
	}

	int cnt = 0;
	int idx = 0;
	
	for (int i = 1; i <= num1; ++i) {
		if (cnt == num2)
			break;
		if (factors[i] != 0) {
			++cnt;
			idx = i;
		}
	}

	if (cnt == num2)
		return factors[idx];
	else
		return 0;

	return 0;
}

int main() {
	int num1, num2;

	cin >> num1 >> num2;


	cout << find_num(num1, num2) << "\n";

	return 0;
}