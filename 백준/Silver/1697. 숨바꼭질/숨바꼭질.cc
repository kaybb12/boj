#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;
using Matrix = vector<vector<int>>;

static array<bool, 100001> is_visited;
static array<int, 3> x_dir = {1, -1, 0};

int get_time(int start_p, int end_p) {
	queue<pair<int, int>> q;
	is_visited[start_p] = true;
	q.push(make_pair(start_p, 0));

	while(!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if (now == end_p) {
			return cnt;
		}

		for (int i = 0; i < 3; ++i) {
			
			int next = now + x_dir[i];

			if (x_dir[i] == 0) {
				next = 2*now;
			}

			if ((next >=0 && next < 100001) &&
				!is_visited[next]) {

				is_visited[next] = true;
				q.push(make_pair(next, cnt+1));
			}
		} 
	}

	return 0;
}

int main() {

	int subin_now, sister_now;
	cin >> subin_now >> sister_now;

	fill(is_visited.begin(), is_visited.end(), false);

	cout << get_time(subin_now, sister_now) << "\n";

	return 0;
}  
