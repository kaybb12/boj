#include <iostream>
#include <string>

using namespace std;

void print_fraction(const int X) {
	int cnt = 1;
	int num = X;	

	while (num > cnt) {
		num -= cnt;
		++cnt;
	}

	if (cnt % 2 == 1) {
		cout << cnt + 1 - num << "/" << num << "\n";
	}
	else {
		cout << num << "/" << cnt + 1 - num << "\n";
	}
}

int main() {
	int X;
	cin >> X;

	print_fraction(X);

	return 0;
}