#include <iostream>

using namespace std;

int is_day(const int noon, const int night, int up) {


	if ((up - noon) % (noon - night) == 0) {
		return (up - noon) / (noon - night) + 1;
	} 
	else {
		return (up - noon) / (noon - night) + 2;
	}

	return 0;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A, B, V;

	cin >> A >> B >> V;
	cout << is_day(A, B, V) << "\n";

	return 0;
}