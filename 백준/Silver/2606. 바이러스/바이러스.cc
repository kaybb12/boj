#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<int>>;

static Matrix computers;
static vector<bool> is_visited;
static int N, M;
static int cnt = 0;


void get_infected_computer(int start) {
	is_visited[start] = true;	

	for  (int i = 0; i < computers[start].size(); ++i) {
		int next = computers[start][i];
		if(!is_visited[next]) {
			get_infected_computer(next);
			cnt++;
		}		
	}
}

int main() {
	cin >> N;
	cin >> M;

	computers.assign(N + 1, vector<int>(0, 0));
	is_visited.assign(N + 1, false);

	for (int i = 1; i <= M; ++i) {
			int temp_x;
			int temp_y;
			cin >> temp_x >> temp_y;

			computers[temp_x].push_back(temp_y);
			computers[temp_y].push_back(temp_x);
	}

	get_infected_computer(1);
	cout << cnt << "\n";

	return 0;
}