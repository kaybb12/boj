#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<bool> rest(42);
	for (int i = 0; i < 10; ++i) {
		int input;
		cin >> input;
		rest[input % 42] = true;
	}

	int cnt = 0;
	for (int i = 0; i < rest.size(); ++i) {
		if (rest[i] == true)
			++cnt;
	}

	cout << cnt << "\n";

	return 0;
}