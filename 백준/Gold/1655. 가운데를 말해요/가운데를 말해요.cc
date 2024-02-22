#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void print_center(vector<int>& nums) {
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;

	for (int i = 0; i < nums.size(); ++i) {
		if (max_pq.size() > min_pq.size())
			min_pq.emplace(nums[i]);
		else
			max_pq.emplace(nums[i]);

		if (!max_pq.empty() && !min_pq.empty()) {
			if (max_pq.top() > min_pq.top()) {
				int a = max_pq.top();
				max_pq.pop();
				int b = min_pq.top();
				min_pq.pop();

				max_pq.emplace(b);
				min_pq.emplace(a);
			}
		}
		cout << max_pq.top() << "\n";
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> nums(n);

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> nums[i];
	}

	print_center(nums);

	return 0;
}