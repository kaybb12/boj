#include <cmath>
#include <iostream>

using namespace std;

inline int count_people(const double h, const double w, const double n, const double m) {
	return ceil(h / (n + 1)) * ceil(w / (m + 1));
}

int main() {

	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	double h, w, n, m;
	cin >> h >> w >> n >> m;

	cout << count_people(h, w, n, m) << "\n";

	return 0;
}
