#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_already_been(const vector<int> vec, const int max) {
	int max_cnt = 0;

	for (const auto v : vec) {
		if (v == max)
			++max_cnt;
	}

	if (max_cnt == 2)
		return true;

	return false;
}

pair <int, int> is_forth_point(const vector<int>& xvec, const vector<int>& yvec) {
	int max_x = *max_element(xvec.begin(), xvec.end());
	int min_x = *min_element(xvec.begin(), xvec.end());
	int max_y = *max_element(yvec.begin(), yvec.end());
	int min_y = *min_element(yvec.begin(), yvec.end());

	int x4;

	if (is_already_been(xvec, max_x))
		x4 = min_x;
	else
		x4 = max_x;

	int y4;

	if (is_already_been(yvec, max_y))
		y4 = min_y;
	else
		y4 = max_y;

	return { x4, y4 };

}

int main() {
	vector <int> rectangle_points_x(3);
	vector <int> rectangle_points_y(3);

	for (int i = 0; i < 3; ++i) {
		cin >> rectangle_points_x[i] >> rectangle_points_y[i];
	}

	auto [x4, y4] = is_forth_point(rectangle_points_x, rectangle_points_y);

	cout << x4 << " " << y4 << "\n";

	return 0;
}