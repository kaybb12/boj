#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

#define MAX 105
using namespace std;

static vector<pair<int, int>> px_map;
static array<bool, MAX> is_visited;
static int num_px, home_x, home_y, target_x, target_y;
static string result;

string cnt_beer() {
	queue<pair<int, int>> q;
	q.push(make_pair(home_y, home_x));

	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (abs(target_y - y) + abs(target_x - x) <= 1000) {
			return "happy";
		}

		for (int i = 0; i < num_px; ++i) {
			int ny = px_map[i].first;
			int nx = px_map[i].second;
			if (is_visited[i])
				continue;
			if (abs(ny - y) + abs(nx - x) <= 1000) {
				is_visited[i] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}

	return "sad";
}

void reset() {
	px_map.clear();
	for (int i = 0; i < MAX; ++i) {
		is_visited[i] = false;
	}
} 

int main () {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; ++test_case) {	
		cin >> num_px;
		cin >> home_x >> home_y;
		
		for (int i = 0; i < num_px; ++i) {
			int x, y;
			cin >> x >> y;
			px_map.push_back({y, x});
		}
		cin >> target_x >> target_y;

		cout << cnt_beer() << "\n";
		reset();
	}

	return 0;
}