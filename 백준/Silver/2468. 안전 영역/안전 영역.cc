#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;
using Matrix = vector<vector<int>>;

static Matrix graph;
static vector<vector<bool>> is_visited;
static array<int, 4> x_dir= {-1, 1, 0, 0};
static array<int, 4> y_dir= {0, 0, -1, 1};
static int max_area = 1;
static int max_height = 0;
static int cnt = 0;
static int n;

void reset() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			is_visited[i][j] = false;
		}
	}
	cnt = 0;
}

void get_max_num(int st_x, int st_y, int height) {
	queue<pair<int, int>> q;
	q.push(make_pair(st_x, st_y));
	is_visited[st_x][st_y] = true;

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + x_dir[i];
			int ny = y + y_dir[i];

			if ((nx >= 0 && nx < n) &&
				(ny >= 0 && ny < n) &&
				(graph[nx][ny] > height) &&
				(!is_visited[nx][ny])) {

				is_visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main () {

	cin >> n;
	graph.assign(n, vector<int>(n, 0));
	is_visited.assign(n, vector<bool>(n, false));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> graph[i][j];
			if (graph[i][j] > max_height)
				max_height = graph[i][j];
		}
	}

	for (int h = 0; h <= max_height; ++h) {
		reset();

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if((graph[i][j] > h) &&
				!is_visited[i][j]) {
					cnt++;
					get_max_num(i, j, h);	
				}
			}
		}

		if (cnt == 0) {
			break;
		}

		if (cnt > max_area) {
			max_area = cnt;
		}
	}

	cout << max_area << "\n";

	return 0;
}