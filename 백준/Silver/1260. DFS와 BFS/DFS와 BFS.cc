#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using Matrix = vector<vector<int>>;

static Matrix graph;
static vector<bool> is_visited;

void reset() {
	for (auto v : is_visited) {
		v = false;
	}
}

void dfs(int cur) {
	is_visited[cur] = true;
	cout << cur << " ";

	for (int i = 0; i < graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (!is_visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	is_visited[start] = true;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (!is_visited[next]) {
				q.push(next);
				is_visited[next] = true;
			}
		}
	}
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;

	graph.assign(n + 1, vector<int> (0,0));
	is_visited.assign(n + 1, false);

	for (int i = 1; i <= m; ++i) {
		int x1, x2;
		cin >> x1 >> x2;

		graph[x1].push_back(x2);
		graph[x2].push_back(x1);
	}

	for (int i = 1; i <= n; ++i) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << "\n";
	reset();
	bfs(v);
	cout << "\n";
}