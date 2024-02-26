#include <iostream>
#include <vector>

using namespace std;

int get_GCD(const int x, const int y) {
	int a, b;

	if (x > y) {
		a = x;
		b = y;
	}
	else {
		a = y;
		b = x;
	}

	while (b != 0) {
		int temp;
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

inline int get_denominator(const int gcd, const vector<pair<int, int>>& nums) {
	return nums[0].second * nums[1].second / gcd;
}

inline int get_numerator(const int den, const vector<pair<int, int>>& nums) {
	return ((den / nums[0].second) * nums[0].first) + ((den / nums[1].second) * nums[1].first);
}

pair<int, int> get_fraction(const vector<pair<int, int>>& nums) {
	int gcd = get_GCD(nums[0].second, nums[1].second);
	int deno = get_denominator(gcd, nums);
	int nume = get_numerator(deno, nums);

	return { deno, nume };
}

pair<int, int> get_reduced_fraction(const vector<pair<int, int>>& nums) {
	auto[ den, num ] = get_fraction(nums);
	
	int gcd = get_GCD(den, num);	
	
	if (gcd != 1) {
		den /= gcd;
		num /= gcd;
	}

	return { den, num };
}

int main() {
	vector<pair<int, int>> nums;
	for (int i = 0; i < 2; ++i) {
		int a, b;
		cin >> a >> b;
		nums.emplace_back(a, b);
	}

	auto[ deno, nume ] = get_reduced_fraction(nums);

	cout << nume << " " << deno << "\n";

	return 0;
}