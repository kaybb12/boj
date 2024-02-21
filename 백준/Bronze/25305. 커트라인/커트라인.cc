#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
	int N, k;
	cin >> N >> k;

	vector<int> scores(N);
	for (int i = 0; i < scores.size(); ++i) {
		cin >> scores[i];
	}

	sort(scores.begin(), scores.end());
	cout << scores[N - k] << "\n";

	return 0;
}