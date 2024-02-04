#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>

using namespace std;

using Graph = vector<vector<int>>;

inline void sort(Graph& graph) {
	for (auto& edges : graph)
		sort(edges.begin(), edges.end());
}

void _dfs(const Graph& graph, vector<bool>& visited, const int cur) {
	visited[cur] = true;

	cout << cur << " "; // print

	for (const auto& next : graph[cur]) {
		if (!visited[next])
			_dfs(graph, visited, next);
	}
}

void dfs(const Graph& graph, const int start) {
	vector<bool> visited(graph.size());

	_dfs(graph, visited, start);

	cout << "\n";
}

void bfs(const Graph& graph, const int start) {
	vector<bool> visited(graph.size());
	queue<int> q;

	q.emplace(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << " "; //print;

		for (const auto& next : graph[cur]) {
			if(!visited[next]) {
				visited[next] = true;
				q.emplace(next);
			}
		}
	}

	cout << "\n";
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int ver_cnt, edge_cnt, start;

	cin >> ver_cnt >> edge_cnt;
	cin >> start;

	Graph graph(ver_cnt + 1);

	for (int i = 0; i < edge_cnt; ++i) {
		int from, to;
		cin >> from >> to;

		graph[from].emplace_back(to);
		graph[to].emplace_back(from);
	}

	sort(graph);

	dfs(graph, start);
	bfs(graph, start);

	return 0;
}