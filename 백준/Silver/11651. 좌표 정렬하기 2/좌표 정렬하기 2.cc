#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using Point = pair<int, int>;

void print_ascending_y(vector<Point>& coordinates) {
	sort(coordinates.begin(), coordinates.end());
	for (const auto& coordinate : coordinates) {
		auto [ y, x ] = coordinate;
		cout << x << " " << y << "\n";
	}
}

int main() {
	int n;
	cin >> n;
	vector<Point> coordinates;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		coordinates.emplace_back(y, x);
	}

	print_ascending_y(coordinates);

	return 0;
}