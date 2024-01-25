#include <iostream>
#include <vector>

using namespace std;

pair<int, int> get_solution(const int a, const int b, const int c, const int d, const int e, const int f) {

	for (int x = -999; x <= 999; ++x) {
		for (int y = -999; y <= 999; ++y) {
			if ((a * x + b * y) == c && (d * x + e * y) == f)
				return { x, y };
		}
	}

	return { 0, 0 };
}

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	auto[x, y] = get_solution(a, b, c, d, e, f);

	cout << x << " " << y << "\n";

	return 0;
}