#include <array>
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

using Matrix = vector<vector<int>>;
using Tensor = vector<Matrix>;
using Point = tuple<int, int, int>;

class TomatoProblem {
	static constexpr int EMPTY = -1;
	static constexpr int UNRIPE = 0;
	static constexpr int RIPE = 1;

	static constexpr array<Point, 6> dirs = { {
		{ 0, 0, 1 }, { 0, 0, -1 },
		{ 0, 1, 0 }, { 0, -1, 0 },
		{ 1, 0, 0 }, { -1, 0, 0 }
	} };

	Tensor tomato_box;
	int m, n, h;

public:
	TomatoProblem(const int m, const int n, const int h) : m{m}, n{n}, h{h} {
		tomato_box = Tensor(h + 2, Matrix(n + 2, vector<int>(m + 2, EMPTY)));

		get_input();
	}

	inline void get_input() {
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= m; ++k)
					cin >> tomato_box[i][j][k];
		}
	}

	void find_ripen_tomato() {
		bfs();
	}

	void bfs() {
		queue<Point> q;

		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= m; ++k)
					if (tomato_box[i][j][k] == RIPE)
						q.emplace(i, j, k);
		}

		while(!q.empty()) {
			auto [r, c, t] = q.front();
			q.pop();

			int date = tomato_box[r][c][t] + 1;

			for (const auto& [ dr, dc, dt ] : dirs) {
				int nr = r + dr;
				int nc = c + dc;
				int nt = t + dt;

				if (tomato_box[nr][nc][nt] == UNRIPE) {
					tomato_box[nr][nc][nt] = date;
					q.emplace(nr, nc, nt);
				}
			}
		}
	}

	inline bool is_all_ripe() {
		for (const auto& mat : tomato_box) {
			for (const auto& vec : mat)
				for (const auto tomato : vec)
					if (tomato == UNRIPE)
						return false;
		}

		return true;
	}

	inline int get_max_date() {
		int max = -1;

		for (const auto& mat : tomato_box) {
			for (const auto& vec : mat)
				for (const auto tomato : vec)
					if (tomato > max)
						max = tomato;
		}

		return max;
	}
};

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int m, n, h;
	cin >> m >> n >> h;

	TomatoProblem problem(m, n, h);
	problem.find_ripen_tomato();

	if (problem.is_all_ripe())
		cout << problem.get_max_date() - 1 << "\n";
	else
		cout << -1 << "\n";

	return 0;
}