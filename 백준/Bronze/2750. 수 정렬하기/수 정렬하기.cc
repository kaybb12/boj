#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> nums(N);

	for (int i = 0; i < nums.size(); ++i) {
		cin >> nums[i];
	} 

	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << "\n";
	}
}