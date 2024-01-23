#include <iostream>

using namespace std;

inline long long is_distance(const long long n) {
	return 4 * n; 
}

int main() {
	long long n;
	cin >> n;

	cout << is_distance(n) << "\n";

	return 0;
}