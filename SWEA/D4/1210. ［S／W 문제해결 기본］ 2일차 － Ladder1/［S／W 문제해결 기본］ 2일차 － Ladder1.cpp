#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;
using MAP = vector<vector<int>>;
using Point = pair<int, int>;

static constexpr int WALL = 0;
static constexpr int PATH = 1;
static constexpr int GOAL = 2;
static array<Point, 2> dir = { {
	{ 0, -1 }, { 0, 1 }
} };

int get_start(Point& goal, MAP& Map) {
	MAP visited(100, vector<int>(100));
	queue<Point> q;

	q.emplace(goal.first, goal.second);
	visited[goal.first][goal.second] = 1;

	while (!q.empty()) {
		Point now = q.front();
		int r = now.first;
		int c = now.second;
		int tunned = 0;
		q.pop();

		if (r == 0) {
			return c;
		}

		for (auto d : dir) {
			int nr = r + d.first;
			int nc = c + d.second;

			if (nr < 0 || nc < 0 ||
				nr >= 100 || nc >= 100) {
				continue;
			}

			if (Map[nr][nc] == WALL) {
				continue;
			}

			if (visited[nr][nc] == 1) {
				continue;
			}

			tunned = 1;
			q.emplace(nr, nc);
			visited[nr][nc] = 1;
		}

		if (tunned != 1) {
			int nr = r - 1;
			int nc = c;

			if (nr < 0 || nc < 0 ||
				nr >= 100 || nc >= 100) {
				continue;
			}

			if (visited[nr][nc] == 1) {
				continue;
			}

			if (Map[nr][nc] == WALL) {
				continue;
			}

			q.emplace(nr, nc);
			visited[nr][nc] = 1;
		}
	}

	return -1;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
    
    for (int i = 0; i < 10; ++i) {
		int tc;
		cin >> tc;
		MAP Map(100, vector<int>(100));
		Point goal;
		for (int r = 0; r < 100; ++r) {
			for (int c = 0; c < 100; ++c) {
				cin >> Map[r][c];
				if (Map[r][c] == 2) {
					goal = { r, c };
				}
			}
		}

		int ans = get_start(goal, Map);

		cout << "#" << tc << " " << ans << "\n";
    }
    
	return 0;
}