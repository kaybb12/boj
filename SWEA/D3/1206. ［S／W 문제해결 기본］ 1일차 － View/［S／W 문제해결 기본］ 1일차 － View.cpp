#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

void print_result(const int testcase, const int result) {
	cout << "#" << testcase << " " << result << "\n";
}

int count_view(const vector<int> &heights) {
	int cnt = 0;

	for (int i = 2; i < heights.size() - 2; ++i) {
		if (heights[i] > heights[i - 1] && heights[i] > heights[i + 1]
			&& heights[i] > heights[i - 2] && heights[i] > heights[i + 2]) {
			int max_height = heights[i - 2];
			
			for (int k = i - 2; k <= i + 2; ++k) {
				if (k == i)
					++k;
				max_height = max(heights[k], max_height);
			}

			cnt += heights[i] - max_height;
		}
	}

	return cnt;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	for (int test_case = 1; test_case <= 10; ++test_case) {
		int N;
		cin >> N;
		vector<int> heights(N + 4);

		for (int i = 2; i < heights.size() - 2; ++i) {
			cin >> heights[i];
		}

		int result = count_view(heights);

		print_result(test_case, result);
	}

	return 0;
}