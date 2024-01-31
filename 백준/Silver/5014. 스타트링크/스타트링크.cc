#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;

static int HEIGHT, target, now; //건물 높이, 스타트링크 위치, 현재 위치
static int up, down; // 업, 다운 가능
static vector<bool> is_visited; // 방문여부
static vector<int> dist;
static array<int, 2> dir;
static bool flag = false;

void get_startlink_cnt(int start) {
	queue<int> q;
	is_visited[start] = true;
	q.push(start);
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < 2; ++i) {
			int next = x + dir[i];

			if (next > 0 && next <= HEIGHT) {
				if (!is_visited[next]) {
					is_visited[next] = true;
					dist[next] = dist[x] + 1;
					q.push(next);					
				}
			}
			if (x == target) {
				flag = true;
				break;
			}
		}
	}
}

int main() {
	cin >> HEIGHT >> now >> target >> up >> down;
	is_visited.assign(HEIGHT + 1, false);
	dist.assign(HEIGHT + 1, 0);
	dir[0] = up;
	dir[1] = -down;

	get_startlink_cnt(now);

	if(flag) {
		cout << dist[target] << "\n";
	}
	else {
		cout << "use the stairs" << "\n";
	}

	return 0;
}