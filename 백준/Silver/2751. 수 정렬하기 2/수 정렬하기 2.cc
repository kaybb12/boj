#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

void print_ascending(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	for (const auto& num : nums)
		cout << num << "\n";
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) 
		cin >> nums[i];

	print_ascending(nums);

	return 0;
}