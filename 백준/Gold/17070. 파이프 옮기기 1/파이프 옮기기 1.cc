#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

using Point = pair<int, int>;
using MAP = vector<vector<int>>;
// 가로일때 이동
static array<Point, 2> dir_g{ {
	{0, 1}, {1, 1}
} };
// 세로일때 이동
static array<Point, 2> dir_s{ {
	{1, 0}, {1, 1}
} };
// 대각선일때 이동
static array<Point, 3> dir_d{ {
	{0, 1}, {1, 0}, {1, 1}
} };

constexpr int WALL = 1;
constexpr int PATH = 0;

void dfs(Point now, const Point& fi, int stat, int& res, MAP& visited, const MAP& Map) {
	if (now.first == fi.first && now.second == fi.second) {
		res++;
		return;
	}

	switch (stat)
	{
	case 0: 
		for (int i = 0; i < dir_g.size(); ++i) {
			Point next = { now.first + dir_g[i].first, now.second + dir_g[i].second };
			int nr = next.first;
			int nc = next.second;
			if (Map[nr][nc] == WALL)
				continue;
			if (visited[nr][nc] == 1)
				continue;
			if (i == 1) {
				if (Map[nr - 1][nc] == WALL || Map[nr][nc - 1] == WALL)
					continue;
				stat = 2;
			}
			visited[nr][nc] = 1;
			
			dfs(next, fi, stat, res, visited, Map);

			visited[nr][nc] = 0;
		}
		break;
	case 1:
		for (int i = 0; i < dir_s.size(); ++i) {
			Point next = { now.first + dir_s[i].first, now.second + dir_s[i].second };
			int nr = next.first;
			int nc = next.second;
			if (Map[nr][nc] == WALL)
				continue;
			if (visited[nr][nc] == 1)
				continue;
			if (i == 1) {
				if (Map[nr - 1][nc] == WALL || Map[nr][nc - 1] == WALL)
					continue;
				stat = 2;
			}
			visited[nr][nc] = 1;

			dfs(next, fi, stat, res, visited, Map);

			visited[nr][nc] = 0;
		}
		break;
	case 2:
		for (int i = 0; i < dir_d.size(); ++i) {
			Point next = { now.first + dir_d[i].first, now.second + dir_d[i].second };
			int nr = next.first;
			int nc = next.second;
			if (Map[nr][nc] == WALL)
				continue;
			if (visited[nr][nc] == 1)
				continue;
			if (i == 2) {
				if (Map[nr - 1][nc] == WALL || Map[nr][nc - 1] == WALL)
					continue;
			}

			stat = i;

			visited[nr][nc] = 1;

			dfs(next, fi, stat, res, visited, Map);

			visited[nr][nc] = 0;
		}
		break;
	default:
		break;
	}
}

int get_case(const MAP& Map) {
	Point st = { 1, 2 };
	Point fi = { Map.size() - 2, Map.size() - 2 };
	int res = 0;
	
	MAP visited(Map.size(), vector<int>(Map.size()));
	dfs(st, fi, 0, res, visited, Map);

	return res;
}

int main() {
		int n;
		cin >> n;
		MAP Map(n + 2, vector<int>(n + 2, 1));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> Map[i][j];
			}
		}

		int ans = get_case(Map);

		cout << ans << "\n";

	return 0;
}