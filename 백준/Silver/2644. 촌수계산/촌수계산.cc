#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> relatives;
vector<bool> is_visited;
int st, ed;
int ans = -1;

void get_relatives_num(int start, int cnt) {
	is_visited[start] = true;

	if (start == ed) {
		ans = cnt;
		return;
	}

	for (int i = 0; i < relatives[start].size(); ++i) {
		int next = relatives[start][i];
		if(!is_visited[next]) {
			get_relatives_num(next, cnt + 1);
		}
	}
}

int main() {
	int N, M;
	cin >> N >> st >> ed >> M;
	relatives.resize(N + 1);
	is_visited.resize(N + 1);
	fill(is_visited.begin(), is_visited.end(), false);

	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y;
		relatives[x].push_back(y);
		relatives[y].push_back(x);
	}

	get_relatives_num(st, 0);
	cout << ans << "\n";

	return 0;
}