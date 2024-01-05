#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline int sum(const int len, const string num) {
	int sum = 0;
	for (int i = 0; i < len; ++i) {
		sum += (num[i] - '0');
	}

	return sum;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int len;
	cin >> len;
	string num;
	cin >> num;

	cout << sum(len, num) << "\n";

	return 0;
}