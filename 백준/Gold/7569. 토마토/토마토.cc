#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<vector<int>>> tomato_box; // 토마토 상태저장
static vector<vector<vector<int>>> date; // 일 수 체크
static vector<vector<vector<bool>>> is_visited; // 방문 여부
static array<int, 6> x_dir = {-1, 1, 0, 0, 0, 0}, y_dir = {0, 0, -1, 1, 0, 0}, z_dir = {0, 0, 0, 0, -1, 1}; // 6방 체크 좌표
static int WIDTH, LENGTH, HEIGHT; // 가로 세로 높이
static int DAY = 0; // 일 수 저장

static queue<pair<pair<int, int>, int>> q;

void get_date() {
	while(!q.empty()) {
		int dx = q.front().first.first;
		int dy = q.front().first.second;
		int dz = q.front().second;
		q.pop();
		for (int i = 0; i < 6; ++i) {
			int nx = dx + x_dir[i];
			int ny = dy + y_dir[i];
			int nz = dz + z_dir[i];

			if ((nx >= 0 && nx < HEIGHT) && 
				(ny >= 0 && ny < LENGTH) &&
				(nz >= 0 && nz < WIDTH) &&
				(!is_visited[nx][ny][nz]) &&
				(tomato_box[nx][ny][nz] == 0)) {

				is_visited[nx][ny][nz] = true;
				tomato_box[nx][ny][nz] = 1;
				date[nx][ny][nz] = date[dx][dy][dz] + 1;

				if (DAY < date[nx][ny][nz]) {
					DAY = date[nx][ny][nz];
				}

				q.push(make_pair(make_pair(nx, ny), nz));
			} 
		}
	}

	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < LENGTH; ++j) {
			for (int k = 0; k < WIDTH; ++k) {
				if (tomato_box[i][j][k] == 0) {
					DAY = -1;
					return;
				}
			}
		}
	}
}

int main() {
	cin >> WIDTH >> LENGTH >> HEIGHT;

	tomato_box.resize(HEIGHT, vector<vector<int>>(LENGTH, vector<int>(WIDTH, 0)));
	date.resize(HEIGHT, vector<vector<int>>(LENGTH, vector<int>(WIDTH, 0)));
	is_visited.resize(HEIGHT, vector<vector<bool>>(LENGTH, vector<bool>(WIDTH, false)));

	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < LENGTH; ++j) {
			for (int k = 0; k < WIDTH; ++k) {
				cin >> tomato_box[i][j][k];
				if (tomato_box[i][j][k] == 1) {
					q.push(make_pair(make_pair(i, j), k));
				}
			}
		}
	}

	get_date();

	cout << DAY << "\n";

	return 0;
}