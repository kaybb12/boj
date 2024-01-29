#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;
using Matrix_int = vector<vector<int>>;
using Matrix_bool = vector<vector<bool>>;

static int N; // 단지 크기
static int cnt = 0; //단지 개수
static int x = 0; // 단지 카운트 시작좌표
static int y = 0; // 단지 카운트 시작좌표
static Matrix_bool is_visited; // 방문 여부 확인
static Matrix_int estates; //단지 저장
static vector<int> estate_nums; // 단지 별 개수 저장
static array<int, 4> x_dir = {-1, 1, 0, 0}; //사방확인 x축
static array<int, 4> y_dir = {0, 0, -1, 1}; //사방확인 y축

void numbering_estate(int start_x, int start_y) {
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	is_visited[start_x][start_y] = true;
	++cnt; 

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();

		//현재 좌표의 사방
		for (int i = 0; i < 4; ++i) {
			int x_new = x + x_dir[i]; 
			int y_new = y + y_dir[i];

			//사방이 미로내의 존재, 방문여부, 이동가능여부확인
			if ((x_new >= 0 && x_new < N) && (y_new >= 0 && y_new <N)
				&& !is_visited[x_new][y_new]
				&& estates[x_new][y_new] == 1) {
				is_visited[x_new][y_new] = true;
				q.push(make_pair(x_new, y_new));
				++cnt;
			}
		}
	}
}

int main() {
	cin >> N;

	estates.assign(N, vector<int>(N, 0));
	is_visited.assign(N, vector<bool>(N, false));
	for (int i = 0; i < estates.size(); ++i) {
		for (int j = 0; j < estates[i].size(); ++j) {
			char temp;
			cin >> temp;
			estates[i][j] = temp - '0';
		}
	}
	
	for (int i = 0; i < estate_nums.size(); ++i) {
		cout << estate_nums[i] << "\n";
	}


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (estates[i][j] == 1 
				&& is_visited[i][j] == false) {
				cnt = 0;
				numbering_estate(i, j);
				estate_nums.push_back(cnt);
			}
		}
	}

	sort(estate_nums.begin(), estate_nums.end());

	cout << estate_nums.size() << "\n";

	for (auto estate_num : estate_nums) {
		cout << estate_num << "\n";
	}

	return 0;
}