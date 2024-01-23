#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string determine_triangle(const int a, const int b, const int c) {
	int max_side = max(max(a, b), c);
	
	if (max_side >= a + b + c - max_side)
		return "Invalid";

	else {
		if (a == b && b == c)
			return "Equilateral";
		else if (a == b || b == c || a == c)
			return "Isosceles";
		else
			return "Scalene";
	}

	return 0;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	while (a != 0 && b != 0 && c != 0) {
		cout << determine_triangle(a, b, c) << "\n";
		cin >> a >> b >> c;
	}

	return 0;
}