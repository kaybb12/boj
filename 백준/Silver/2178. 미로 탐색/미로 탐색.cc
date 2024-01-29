#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;
using Matrix = vector<vector<int>>; 
static vector<vector<bool>> is_visited; // 방문 체크
static Matrix graph; // 미로 저장
static Matrix dist; // 이동칸 기록
static array<int, 4> x_dir = {-1, 1, 0, 0}; //사방 x축
static array<int, 4> y_dir = {0, 0, -1, 1}; //사방 y축
static int N, M; //미로크기


int get_min_route(int start_x, int start_y) {
	is_visited[start_x][start_y] = true; // 시작점 표시
	queue<pair<int, int>> q; 
	q.push(make_pair(start_x, start_y)); // q에 삽입
	dist[start_x][start_y]++; // 시작 좌표까지 이동한칸을 1로 지정

	while(!q.empty()) {
		int x = q.front().first; //x 
		int y = q.front().second; //y

		// q의 front 좌표 삭제
		q.pop();

		//현재 위치에 사방 확인
		for (int i = 0; i < 4; ++i) {

			//현재 좌표의 사방
			int x_new = x + x_dir[i];
			int y_new = y + y_dir[i];

			//사방이, 미로내에 존재, 방문여부, 이동가능여부 확인
			if ((x_new >= 0 && x_new < N) 
				&& (y_new >= 0 && y_new < M)
				&& !is_visited[x_new][y_new]
				&& graph[x_new][y_new] == 1) {

				is_visited[x_new][y_new] = true;
				q.push(make_pair(x_new, y_new));
				dist[x_new][y_new] = dist[x][y] + 1;
			}
		}
	}

	return dist[N-1][M-1];
}

int main() {
	
	cin >> N >> M;

	graph.assign(N, vector<int>(M, 0));
	dist.assign(N, vector<int>(M, 0));
	is_visited.assign(N, vector<bool>(M, false));
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char temp;
			cin >> temp;
			graph[i][j] = temp - '0';
		}
	}

	cout << get_min_route(0, 0) << "\n";

	return 0;
}