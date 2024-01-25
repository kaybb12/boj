#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int get_max_sum(const int target, const vector<int>& nums) {
	int result = 0;

	for (int i = 0; i < nums.size() - 2; ++i) {
		for (int j = i + 1; j < nums.size() - 1; ++j) {
			for (int k = j + 1; k < nums.size(); ++k) {
				if (nums[i] + nums[j] + nums[k] < target) {
					result = max(result, nums[i] + nums[j] + nums[k]);
				}
				else if (nums[i] + nums[j] + nums[k] == target) {
					return target;
				}
			}
		}
	}

	return result;
}

int main() {
	int card_num, target;
	cin >> card_num >> target;
	vector<int> nums(card_num);

	for (int i = 0; i < nums.size(); ++i) {
		cin >> nums[i];
	}

	cout << get_max_sum(target, nums) << "\n";

	return 0;
}