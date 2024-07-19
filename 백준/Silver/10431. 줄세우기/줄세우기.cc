#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_count(vector<int>& heights) {
	int cnt = 0;

	for (int i = 0; i < heights.size(); ++i) {
		for (int j = heights.size() - 1; j > i; --j) {
			if (heights[j - 1] > heights[j]) {
				swap(heights[j - 1], heights[j]);
				++cnt;
			}
		}
	}

	return cnt;
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		int test_num;
		cin >> test_num;

		vector<int> heights(20);

		for (int i = 0; i < heights.size(); ++i) {
			cin >> heights[i];
			//cout << i << " " << heights[i] << " ";
		}

		cout << test_num << " " << get_count(heights) << "\n";
	}

	return 0;
}