#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
	array<int, 5> nums;
	int avg = 0;
	for (int i = 0; i < nums.size(); ++i) {
		cin >> nums[i];
		avg += nums[i];
	}

	sort(nums.begin(), nums.end());
	cout << avg / 5 << "\n"; 
	cout << nums[2] << "\n";

	return 0;
}