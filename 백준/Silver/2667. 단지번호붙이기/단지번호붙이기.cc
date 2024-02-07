#include <array>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using Matrix = vector<vector<char>>;
using Point = pair<int, int>;

static constexpr char EMPTY = '0';
static constexpr char HOUSE = '1';
static constexpr char CHECKED = '0';

static constexpr array<pair<int, int>, 4> dirs = { {
	{ 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }
}};

int bfs(Matrix& map, const int start_r, const int start_c) {
	queue<Point> q;
	q.emplace(start_r, start_c);

	map[start_r][start_c] = CHECKED;

	int area = 0;
	while (!q.empty()) {
		auto [ r, c ] = q.front();
		q.pop();
		++area;

		for (const auto& [ dr, dc ] : dirs) {
			int nr = r + dr;
			int nc = c + dc;

			if (map[nr][nc] == HOUSE) {
				map[nr][nc] = CHECKED;
				q.emplace(nr, nc);
			}
		}
	}

	return area;
}

vector<int> get_areas(Matrix& map) {
	vector<int> areas;

	for (int i = 1; i < map.size(); ++i) {
		for (int j = 1; j < map[i].size(); ++j) {
			if (map[i][j] == HOUSE) {
				int area = bfs(map, i, j);
				areas.emplace_back(area);
			}
		}
	}

	return areas;
}

inline void print_area_info(const vector<int>& areas) {
	// area count
	cout << areas.size() << "\n";

	// each area
	for (const auto area : areas) {
		cout << area << "\n";
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	Matrix map(n + 2, vector<char>(n + 2, EMPTY));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
		}
	}

	vector<int> areas = get_areas(map);
	sort(areas.begin(), areas.end());

	print_area_info(areas);

	return 0;
}