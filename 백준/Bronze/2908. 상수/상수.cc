#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline int compare_num(const string& num1, const string& num2) {
	return max(stoi(num1), stoi(num2));
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string num1, num2;
	cin >> num1 >> num2;

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	cout << compare_num(num1, num2) << "\n";

	return 0;
}